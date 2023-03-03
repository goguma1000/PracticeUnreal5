언리얼 C\+\+ 프로그래밍 공부
===
## 참고 교재 \: 이득우의 언리얼 C\+\+ 게임 개발의 정석
---
### 2023\-01\-24
학습내용: 교재 chapter2 실습
<br>
#### Fountain.h
~~~cpp
class MYACTORS_API AFountain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFountain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Water;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Body;

	UPROPERTY(VisibleAnywhere)
	UPointLightComponent* Light;
	
	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* Splash;

	UPROPERTY(EditAnywhere, Category=ID)
	int32 ID;
};
~~~

#### Fountain.cpp

~~~cpp
//Fountain.cpp
AFountain::AFountain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));
	Water = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WATER"));
	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("LIGHT"));
	Splash = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("SPLASH"));

	RootComponent = Body;
	Water->SetupAttachment(Body);
	Light->SetupAttachment(Body);
	Splash->SetupAttachment(Body);

	Water->SetRelativeLocation(FVector(0.0f, 0.0f, 135.0f));
	Light->SetRelativeLocation(FVector(0.0f, 0.0f, 195.0f));
	Splash->SetRelativeLocation(FVector(0.0f, 0.0f, 195.0f));

  static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_BODY(TEXT("/Game/InfinityBladeGrassLands/Environments/Plains/Env_Plains_Ruins/StaticMesh/SM_Plains_Castle_Fountain_01.SM_Plains_Castle_Fountain_01"));
  if (SM_BODY.Succeeded()) {
    Body->SetStaticMesh(SM_BODY.Object);
  }

  static ConstructorHelpers::FObjectFinder<UStaticMesh>SM_WATER(TEXT("/Game/InfinityBladeGrassLands/Effects/FX_Meshes/Env/SM_Plains_Fountain_02.SM_Plains_Fountain_02"));
  if (SM_WATER.Succeeded()) {
    Water->SetStaticMesh(SM_WATER.Object);
  }

  static ConstructorHelpers::FObjectFinder<UParticleSystem>PS_SPLASH(TEXT("/Game/InfinityBladeGrassLands/Effects/FX_Ambient/Water/P_Water_Fountain_Splash_Base_01.P_Water_Fountain_Splash_Base_01"));
  if (PS_SPLASH.Succeeded()) {
    Splash->SetTemplate(PS_SPLASH.Object);
  }

}  
~~~
<br>

#### 학습내용 정리

1. 헤더파일에 멤버변수를 선언하고 그 위에 UPROPERTY 매크로를 선언하여 언리얼 엔진에서 메모리를 자동으로 관리하도록 함.

   단 UPROPERTY 매크로는 언리얼 오브젝트만 관리하며 언리얼 오브젝트는 접두서 'U'나 'A'가 붙는다 (U:엑터x , A: 엑터)

2. UPROPERTY 매크로에 VisitAnywhere 키워드를 사용하면 에디터에서 객체의 속성 값을 편집할 수 있다.
   단 int와 같은 유형은 속성 값을 변경할 수 없으며, 객체 유형만 속성들을 변경할 수 있다.
   따라서 int와 같은 유형은 EditAnywhere 키워드를 사용한다.
   
3. CreateDefaultSubobject<Type>(Name)함수로 컴포넌트 생성, RootComponent에 컴포넌트를 할당하여 엑터를 대표할 컴포넌트 할당.

   SetupAttachment(Object)함수로 자식 컴포넌트 설정.
   
   SetRelativeLocation(Fvector)함수로 상대적 위치 설정, 생성자에서 설정하기 떄문에 디폴트값이 됨. 

4. 생성자에서 에셋을 설정하기 위해 ConstructorHelpers 클래스의 FObjectFinder함수로 에셋을 찾음.   
<br>

### 2023\-01\-26
학습내용: 교재 chapter3 실습
<br>

### MyActors.h
~~~cpp

DECLARE_LOG_CATEGORY_EXTERN(Practice,Log,All);

#define ABLOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))
#define ABLOG_S(Verbosity) UE_LOG(Practice, Verbosity, TEXT("%s"), *ABLOG_CALLINFO)
#define ABLOG(Verbosity, Format, ...) UE_LOG(Practice, Verbosity, TEXT("%s %s"), *ABLOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))

~~~

### MyActors.h
~~~cpp

#include "MyActors.h"
#include "Modules/ModuleManager.h"

DEFINE_LOG_CATEGORY(Practice);
IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, MyActors, "MyActors" );
~~~

### Fountain.h
~~~cpp
#include "MyActors.h"
#include "GameFramework/RotatingMovementComponent.h"
...
protected:
	...
	virtual void PostInitializeComponents() override;

...

private:
	UPROPERTY(EditAnyWhere, Category = Stat, Meta = (AllowPrivateAccess = true))
	float RotateSpeed;
};
~~~

### Fountain.cpp
~~~cpp

AFountain::AFountain()
{
 	...
	Movement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("MOVEMENT"));
	...
	RotateSpeed = 30.0f;
	Movement->RotationRate = (FRotator(0.0f, RotateSpeed, 0.0f));
}

~~~

<br>

#### 학습내용 정리

1. 언리얼 엔진은 로그 카테고리를 정의할 수 있으며 로그 카테고리를 선언하기 위해 게임 모듈명으로 된 헤더파일과 소스파일에 DECLARE_LOG_CATEGORY_EXTERN 와 DEFINE_LOG_CATEGORY 매크로를 각각 선언한다.

   UE_LOG매크로를 사용하여 로그를 출력할 수 있다.
   
   '##__VA_ARGS__'는 가변인자 매크로이다. 함수를 정의할 때 인자의 갯수로 정확히 몇개가 올지 모를 때 가변인자 매크로를 사용하며 파라미터 맨 끝에 '...'을 사용한다.  가변인자는 stack구조를 사용하여 데이터를 저장한다.
   
   __VA_ARGS__는 파라미터가&nbsp;','로 끝나면(가변인수가 한개도 안들어오면) 컴파일러에서 에러가 발생한다. &nbsp;이 대안으로 ##__VA_ARGS__가 있다. &nbsp; ##__VA_ARGS__는 &nbsp;','로 끝나도 &nbsp;','를 무시하여 컴파일에서 에러가 발생하지 않는다.
   
2. 언리얼 엔진은 엑터에 속한 모든 컴포넌트가 세팅이 완료되면 PostInitializeComponent 함수를 호출하고, 게임에 참여하면 BeginPlay함수를 호출하며, 게임에서 퇴장하면 EndPlay함수를 호출한다.

3. 언리얼 엔진은 UPROPERTY에 EditAnywhere매크로를 사용하여 에디터에서 변수 값을 수정할 수 있지만, 그 변수를 private로 선언하면 컴파일 과정에서 에러가 생긴다. 따라서 UPROPERTY에 AllowPrivateAccess라는 META키워드를 추가하여 에디터에서 그 변수를 편집함과 동시에 데이터를 은닉할 수 있다.

4.언리얼 엔진은 Tick함수를 구현하지 않아도 엑터를 움직일 수 있게하는 무브먼트 컴포넌트를 제공한다.

    -FloatingPawnMovement: 중력의 영향을 받지 않는 엑터의 움직임을 제공한다. 입력에 따라 자유롭게 움직이도록 설계됨.
  
    -RotatingMovement: 지정한 속도로 엑터를 회전시킨다.
  
    -InterpMovement: 지정한 위치로 액터를 이동시킨다.
  
    -ProjectileMovement: 엑터에 중력의 영향을 받아 포물선을 그리는 발사체의 움직임을 제공.
  
### 2023\-01\-29
학습내용: 교재 chapter4 실습
<br>

### ABGameMode.h
~~~cpp
	
#include "MyActors.h"
#include "GameFramework/GameModeBase.h"
#include "ABGameMode.generated.h"
	
UCLASS()
class MYACTORS_API AABGameMode : public AGameModeBase
{
	GENERATED_BODY()

	AABGameMode();

public:
	virtual void PostLogin(APlayerController* NewPlayer) override;
};
	
~~~

### ABGameMode.cpp
~~~cpp

#include "ABGameMode.h"
#include "ABPawn.h"
#include "ABPlayerController.h"

AABGameMode::AABGameMode() {
	DefaultPawnClass = AABPawn::StaticClass();
	PlayerControllerClass = AABPlayerController::StaticClass();

}

void AABGameMode::PostLogin(APlayerController* NewPlayer) {
	ABLOG(Warning, TEXT("PostLogin Being"));
	Super::PostLogin(NewPlayer);
	ABLOG(Warning, TEXT("PostLogin End"));
}

~~~

### ABPawn.h
~~~cpp

#pragma once

#include "MyActors.h"
#include "GameFramework/Pawn.h"
#include "ABPawn.generated.h"

UCLASS()
class MYACTORS_API AABPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AABPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PostInitializeComponents() override;
	virtual void PossessedBy(AController* NewController) override;

};
	
~~~

### ABPawn.cpp
~~~cpp

#include "ABPawn.h"

// Sets default values
AABPawn::AABPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called to bind functionality to input
void AABPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AABPawn::PostInitializeComponents() {
	Super::PostInitializeComponents();
	ABLOG_S(Warning);
}

void AABPawn::PossessedBy(AController* NewController) {
	ABLOG_S(Warning);
	Super::PossessedBy(NewController);
}

~~~
	
### ABPlayerController.h
~~~cpp

#pragma once

#include "MyActors.h"
#include "GameFramework/PlayerController.h"
#include "ABPlayerController.generated.h"


UCLASS()
class MYACTORS_API AABPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void PostInitializeComponents() override;
	virtual void OnPossess(APawn* aPawn) override;
};

~~~
	
### ABPlayerController.cpp
~~~cpp

#include "ABPlayerController.h"

void AABPlayerController::PostInitializeComponents() {
	Super::PostInitializeComponents();
	ABLOG_S(Warning);
}

void AABPlayerController::OnPossess(APawn* aPawn) {
	ABLOG_S(Warning);
	Super::OnPossess(aPawn);
	
}

~~~
	
<br>

#### 학습내용 정리
1. 언리얼 오브젝트의 클래스 정보는 StaticClass 스태틱 함수를 호출하여 가져올 수 있다.

2. 언리얼 엔진에선 플레이어가 플레이어 컨트롤러를 통해 폰을 조종하는 것을 possess라고 한다.
  ![1](https://user-images.githubusercontent.com/102130574/215333362-f2b9eed5-b62a-483a-8caf-412ba64654ad.PNG)
  
    에디터의 플레이 버튼을 누르면 위 로그 처럼 플레이어 컨트롤러가 생성되고, 플레이어 설정이 시작된다. &nbsp;우선 플레이어 폰을 생성하고 &nbsp;플레이어 컨트롤러를 폰에 posseess하고 플레이어 설정이 끝나면 GameMode에서 PostLogin 함수를 호출한다.  
### 2023\-01\-31
학습내용: 교재 chapter5 실습
<br>

### ABPawn.h
~~~cpp
class MYACTORS_API AABPawn : public APawn
{
	...
public:	
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PostInitializeComponents() override;
	virtual void PossessedBy(AController* NewController) override;

	UPROPERTY(VisibleAnywhere, Category = Collision)
	UCapsuleComponent* Capsule;
	
	UPROPERTY(VisibleAnywhere, Category = Visual)
	USkeletalMeshComponent* Mesh;
	
	UPROPERTY(VisibleAnywhere, Category = Movement)
	UFloatingPawnMovement* Movement;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	UCameraComponent* Camera;
	
private:
	void MoveForward(float NewAxisValue);
	void MoveRight(float NewAxisValue);
};
~~~

### ABPawn.cpp
~~~cpp
AABPawn::AABPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CAPSULE"));
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MESH"));
	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MOVEMENT"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	RootComponent = Capsule;
	Mesh->SetupAttachment(Capsule);
	SpringArm->SetupAttachment(Capsule);
	Camera->SetupAttachment(SpringArm);
	
	Capsule->SetCapsuleHalfHeight(88.0f);
	Capsule->SetCapsuleRadius(34.0f);
	Mesh->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_CARDBOARD(TEXT("/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Cardboard.SK_CharM_Cardboard"));
	if (SK_CARDBOARD.Succeeded()) {
		Mesh->SetSkeletalMesh(SK_CARDBOARD.Object);
	}

	Mesh->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	static ConstructorHelpers::FClassFinder<UAnimInstance>WARRIOR_ANIM(TEXT("/Game/Animations/WarriorAnimBlueprint.WarriorAnimBlueprint_C"));
	if (WARRIOR_ANIM.Succeeded()) {
		Mesh->SetAnimInstanceClass(WARRIOR_ANIM.Class);
	}

}

...
void AABPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AABPawn::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AABPawn::MoveRight);
}

void AABPawn::PostInitializeComponents() {
	Super::PostInitializeComponents();
	ABLOG_S(Warning);
}

void AABPawn::PossessedBy(AController* NewController) {
	ABLOG_S(Warning);
	Super::PossessedBy(NewController);
}

void AABPawn::MoveForward(float NewAxisValue) {
	AddMovementInput(GetActorForwardVector(), NewAxisValue);
}

void AABPawn::MoveRight(float NewAxisValue) {
	AddMovementInput(GetActorRightVector(), NewAxisValue);
}

~~~

<br>

#### 학습내용 정리
1. SpringArm은 카메라 구도를 편리하게 설정할 수 있는 컴포넌트로 카메라를 SpringArm의 자식으로 설정하고 트랜스 폼을 초기화 하여 자동으로 SpringArm의 끝에 걸린다.

2. 언리얼 엔진은 입력을 처리하기 위해 InputComponent라는 컴포넌트를 사용한다.

   폰의 맴버 함수와 입력 설정을 Binding하면 입력이 폰의 맴버 함수의 인자로 전달된다.
   
   이를 Binding하는 함수는 SetupInputComponent 함수이다. BindAxis함수를 사용하여 입력 설정의 이름과 연동할 언리얼 오브젝트 인스터스 함수 포인터를 지정한다.
	 
3. 코드로 재생할 애니메이션을 지정할 수 있지만, 규모가 커지면 관리가 힘들기 때문에 언리얼 엔진에서 체계적인 애니메이션 시스템을 설계하기 위해 애니메이션 블루프린트 시스템을 제공한다.
    
   언리얼 엔진은 Anim Instance 클래스로 애니메이션 시스템을 관리한다.

    스켈레탈 메시 컴포넌트는 자신의 캐릭터의 애니메이션을 Anim Instance에 위임하는 구조로 설계돼 있다.

    스켈레탈 메시가 애니메이션 블루프린트를 실행시키려면 블루프린트 애셋의 클래스 정보를 Anim Instance 속성에 지정해야 한다. &nbsp; 클래스 정보를 얻기위해 애셋의 래퍼런스 경로 뒤에 &nbsp;'_C'를 붙인다. 
  
### 2023\-02\-01
학습내용: 교재 chapter6 실습
<br>

### ABCharacter.h
~~~cpp

#pragma once

#include "MyActors.h"
#include "GameFramework/Character.h"
#include "ABCharacter.generated.h"

UCLASS()
class MYACTORS_API AABCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AABCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	enum class EControlMode {

		GTA,
		DIABLO
	};

	void SetControlMode(EControlMode NewControlMode);
	EControlMode CurrentControlMode = EControlMode::GTA;
	FVector DirectionToMove = FVector::ZeroVector;

	float ArmLengthTo = 0.0f;
	FRotator ArmRotationTo = FRotator::ZeroRotator;
	float ArmLengthSpeed = 0.0f;
	float ArmRotationSpeed = 0.0f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	UCameraComponent* Camera;

private:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);
	void Turn(float NewAxisValue);
	void LookUp(float NewAxisValue);
	void SetControlMode(int32 ControlMode);
	void ViewChange();
};

~~~

### ABCharacter.cpp
~~~cpp

#include "ABCharacter.h"

// Sets default values
AABCharacter::AABCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh>SK_CARDBOARD(TEXT("/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Cardboard.SK_CharM_Cardboard"));
	if (SK_CARDBOARD.Succeeded()) {
		GetMesh()->SetSkeletalMesh(SK_CARDBOARD.Object);
	}

	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	static ConstructorHelpers::FClassFinder<UAnimInstance> WARRIOR_ANIM(TEXT("/Game/Animations/WarriorAnimBlueprint.WarriorAnimBlueprint_C"));
	if (WARRIOR_ANIM.Succeeded()) {
		GetMesh()->SetAnimInstanceClass(WARRIOR_ANIM.Class);
	}

	SetControlMode(EControlMode::DIABLO);

	ArmLengthSpeed = 3.0f;
	ArmRotationSpeed = 10.0f;
}

// Called when the game starts or when spawned
void AABCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AABCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SpringArm->TargetArmLength = FMath::FInterpTo(SpringArm->TargetArmLength, ArmLengthTo, DeltaTime, ArmLengthSpeed);

	switch (CurrentControlMode)
	{
	case EControlMode::DIABLO:
		SpringArm->SetRelativeRotation(FMath::RInterpTo(SpringArm->GetRelativeRotation(), ArmRotationTo, DeltaTime, ArmRotationSpeed));
		if (DirectionToMove.SizeSquared() > 0.0f) {
			GetController()->SetControlRotation(FRotationMatrix::MakeFromX(DirectionToMove).Rotator());
			AddMovementInput(DirectionToMove);
		}
		break;
	default:
		break;
	}

}

// Called to bind functionality to input
void AABCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AABCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AABCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AABCharacter::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AABCharacter::LookUp);

	PlayerInputComponent->BindAction(TEXT("ViewChange"), EInputEvent::IE_Pressed, this, &AABCharacter::ViewChange);
}

void AABCharacter::UpDown(float NewAxisValue) {
	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X), NewAxisValue);
		break;
	case EControlMode::DIABLO:
		DirectionToMove.X = NewAxisValue;
		break;
	default:
		break;
	}
}

void AABCharacter::LeftRight(float NewAxisValue) {
	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::Y), NewAxisValue);
		break;
	case EControlMode::DIABLO:
		DirectionToMove.Y = NewAxisValue;
		break;
	default:
		break;
	}
}

void AABCharacter::Turn(float NewAxisValue) {
	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		AddControllerYawInput(NewAxisValue);
		break;
	default:
		break;
	}
}

void AABCharacter::LookUp(float NewAxisValue) {
	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		AddControllerPitchInput(NewAxisValue);
		break;
	default:
		break;
	}
}

void AABCharacter::SetControlMode(EControlMode NewControlMode) {
	
	CurrentControlMode = NewControlMode;
	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		//SpringArm->TargetArmLength = 450.0f;
		//SpringArm->SetRelativeRotation(FRotator::ZeroRotator);
		ArmLengthTo = 450.f;
		SpringArm->bUsePawnControlRotation = true;
		SpringArm->bInheritPitch = true;
		SpringArm->bInheritYaw = true;
		SpringArm->bInheritRoll = true;
		SpringArm->bDoCollisionTest = true;
		bUseControllerRotationYaw = false;
		GetCharacterMovement()->bOrientRotationToMovement = true;
		GetCharacterMovement()->bUseControllerDesiredRotation = false;
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
		break;

	case EControlMode::DIABLO:
		//SpringArm->TargetArmLength = 800.0f;
		//SpringArm->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
		ArmLengthTo = 800.0f;
		ArmRotationTo = FRotator(-45.0f, 0.0f, 0.0f);
		SpringArm->bUsePawnControlRotation = false;
		SpringArm->bInheritPitch = false;
		SpringArm->bInheritRoll = false;
		SpringArm->bInheritYaw = false;
		SpringArm->bDoCollisionTest = false;
		bUseControllerRotationYaw = false;
		GetCharacterMovement()->bOrientRotationToMovement = false;
		GetCharacterMovement()->bUseControllerDesiredRotation = true;
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
		break;

	default:
		break;
	}
	
}

void AABCharacter::ViewChange() {
	switch (CurrentControlMode) {
	case EControlMode::GTA:
		GetController()->SetControlRotation(GetActorRotation());
		SetControlMode(EControlMode::DIABLO);
		break;
	case EControlMode::DIABLO:
		GetController()->SetControlRotation(SpringArm->GetRelativeRotation());
		SetControlMode(EControlMode::GTA);
		break;
	}
}
~~~

<br>

#### 학습내용 정리
1. 언리얼 엔진은 플레이어블 폰을 좀더 효율적으로 제작하기 위해 Character클래스를 제공.

   Character클래스는 Pawn 클래스를 상속받고 있다.
   
   Character클래스는 위에서 작성한 ABPawn과 동일하게 Capsule 컴포넌트, SkeletalMesh 컴포넌트를 사용하며 CharacterMovement 컴포넌트를 사용하여 움직임을 관리.
   
   CharacterMovement 컴포넌트는 FloatingPawnMovement 컴포넌트에 비해 다음과 같은 장점을 가지고 있다.
   
       *점프와 같은 중력을 반영한 움직임을 제공.
       *기어가기, 수영, 비행등 다양한 이동 모드를 설정할 수 있고, 현재 움직임에 대해 좀 더 많은 정보를 전달.
       *멀티 플레이 네트워크 환경에서 캐릭터 움직임을 자동으로 동기화.
   
2. 언리얼 엔진은 캐릭터의 회전을 위해 AddControllerInpuYaw, Roll, Pitch라는 세 가지 명령어를 제공함.

       *Yaw: z축 회전
       *Roll: y축 회전
       *Pitch: x축 회전
    
    언리얼 엔진의 Character모델은 기본적으로 컨트롤 회전의 Yaw회전과 Pawn의 Yaw회전이 연동돼 있고, 이를 지정하는 속성이 액터의 Pawn섹션에 위치한 UseControllerRotationYaw이다.
 
    캐릭터 무브먼트 컴포넌트의 OrientRotationToMovement 기능을 사용하면 캐릭터가 움직이는 방향으로 캐릭터를 회전시켜준다.
    
3. C++은 class키워드로 열거형을 선언하는 방식과 class없이 선언하는 방식이 있는데 전자의 방식은 다른 열거형 간의 묵시적 변환을 혀용하지 않는다.

4. 언리얼 엔진의 Axis 이벤트와 Tick 이벤트는 모두 매 프레임마다 호출되는데, 플레이어의 입력 값에 따라 엑터의 행동을 결정해야 하므로, 두 이벤트 함수가 매프레임마다 호출되더라도 입력함수를 먼저 호출한다.

### 2023\-02\-04
학습내용: 교재 chapter7 실습
<br>

### ABAnimInstance.h
~~~cpp
#pragma once

#include "MyActors.h"
#include "Animation/AnimInstance.h"
#include "ABAnimInstance.generated.h"

UCLASS()
class MYACTORS_API UABAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UABAnimInstance();
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	float CurrentPawnSpeed = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsInAir;
};

~~~

### ABAnimInstance.h
~~~cpp
#include "ABAnimInstance.h"

UABAnimInstance::UABAnimInstance() {
	CurrentPawnSpeed = 0.0f;
	IsInAir = false;
}

void UABAnimInstance::NativeUpdateAnimation(float DeltaSeconds) {
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (::IsValid(Pawn)) {
		CurrentPawnSpeed = Pawn->GetVelocity().Size();
		auto Character = Cast<ACharacter>(Pawn);
		if (Character) {
			IsInAir = Character->GetMovementComponent()->IsFalling();
		}
	}
}

~~~

### ABCharacter.cpp
~~~cpp
//점프기능
AABCharacter::AABCharacter()
{
	...
	GetCharacterMovement()->JumpZVelocity = 800.0f;
}

void AABCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
        ...
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
}

~~~

#### 학습내용 정리
1. 언리얼 엔진에서 제공하는 애니메이션 블루프린트는 애님 그래프와 애님 인스턴스로 구성되어있다.
	
		*애님 인스턴스: 스켈레탈 메시를 소유하는 폰의 정보를 받아 애님그래프가 참조할 데이터를 제공.
		*애님 그래프: 애님 인스턴스의 변수 값에 따라 변화하는 애니메이션 시스템을 설계하는 공간.

2. 블루프린트에서 변수에 접근할 수 있게 UPROPERTY매크로에 BlueprintReadOnly, BlueprintReadWrite 키워드를 작성한다.

3. 애님 인스턴스 클래스는 틱마다 호출되는 NativeAnimationUpdate 함수를 제공한다.
   
   언리얼 엔진은 입력시스템->게임 로직->애니메이션 시스템순으로 로직을 실행한다.
   
   플레이어의 입력을 받은 후 그 입력을 처리하고 애니메이션을 실행하는 것이 자연스럽기 때문.

4. 언리얼 엔진은 스켈레톤 구성이 달라도 애니메이션을 교환할 수 있는 애니메이션 리타겟이란 기능을 제공한다.
   
   언리얼 엔진5에서 애니메이션 리타겟을 사용하는 방법은 다음과 같다.
   
   		*소스 스켈레톤의 IK_Rig을 만든 후 연동할 본(Bone)들을 체인한다.
		*타겟 스켈레톤의 IK_Rig도 위와 동일한 방식으로 제작한다.
		*IK_리타기터를 생성 후 리타깃 할 소스IK와 타깃IK를 할당한다.
		*복제할 애니메이션을 선택후 애니메이션 에셋 리타겟 버튼을 눌러 리타기터를 할당한 후 애니메이션을 복제한다.
	* 결과 ![1234](https://user-images.githubusercontent.com/102130574/217860557-1cd7c80b-a2df-41c3-ad7b-8cd9cb27e298.PNG)
	
### 2023\-02\-07
학습내용: 교재 chapter8 실습
<br>

### ABCharacter.h
~~~cpp
...
private:
	...
	void Attack();

	UFUNCTION()
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	void AttackStartComboState();
	void AttackEndComboState();

private:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	bool IsAttacking;

	UPROPERTY()
	class UABAnimInstance* ABAnim;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	bool CanNextCombo;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	bool IsComboInputOn;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	int32 CurrentCombo;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	int32 MaxCombo;
};

~~~

### ABCharacter.cpp
~~~cpp
...
#include "ABAnimInstance.h"

AABCharacter::AABCharacter()
{
 	...
	IsAttacking = false;

	MaxCombo = 4;
	AttackEndComboState();
}
void AABCharacter::PostInitializeComponents() {
	Super::PostInitializeComponents();
	ABAnim = Cast<UABAnimInstance>(GetMesh()->GetAnimInstance());
	ABCHECK(nullptr != ABAnim);
	ABAnim->OnMontageEnded.AddDynamic(this, &AABCharacter::OnAttackMontageEnded);
	ABAnim->OnNextAttackCheck.AddLambda([this]()->void {
		ABLOG(Warning, TEXT("OnNextAttackCheck"));
		CanNextCombo = false;
		if (IsComboInputOn) {
			AttackStartComboState();
			ABAnim->JumpToAttackMontageSection(CurrentCombo);
		}
	});
}
...
void AABCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	...
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &AABCharacter::Attack);
}

...

void AABCharacter::Attack() {
	if (IsAttacking) {
		ABCHECK(FMath::IsWithinInclusive<int32>(CurrentCombo, 1, MaxCombo));
		if (CanNextCombo) {
			IsComboInputOn = true;
		}
	}
	else {
		ABCHECK(CurrentCombo == 0);
		AttackStartComboState();
		ABAnim->PlayAttackMontage();
		ABAnim->JumpToAttackMontageSection(CurrentCombo);
		IsAttacking = true;
	}
}

void AABCharacter::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted) {
	ABCHECK(IsAttacking);
	ABCHECK(CurrentCombo > 0);
	IsAttacking = false;
	AttackEndComboState();

}

void AABCharacter::AttackStartComboState() {
	CanNextCombo = true;
	IsComboInputOn = false;
	ABCHECK(FMath::IsWithinInclusive<int32>(CurrentCombo, 0, MaxCombo - 1));
	CurrentCombo = FMath::Clamp<int32>(CurrentCombo + 1, 1, MaxCombo);
	
}

void AABCharacter::AttackEndComboState() {
	IsComboInputOn = false;
	CanNextCombo = false;
	CurrentCombo = 0;
}

~~~

### ABAnimInstance.h
~~~cpp
#pragma once

#include "MyActors.h"
#include "Animation/AnimInstance.h"
#include "ABAnimInstance.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnNextAttackCheckDelegate);
DECLARE_MULTICAST_DELEGATE(FOnAttackHitCheckDelegate);

UCLASS()
class MYACTORS_API UABAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	...
	void PlayAttackMontage();
	void JumpToAttackMontageSection(int32 NewSection);
public:
	FOnNextAttackCheckDelegate OnNextAttackCheck;
	FOnAttackHitCheckDelegate OnAttackHitCheck;
private:
	UFUNCTION()
	void AnimNotify_AttackHitCheck();
	UFUNCTION()
	void AnimNotify_NextAttackCheck();

	FName GetAttackMontageSectionName(int32 Section);
private:
	...
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	UAnimMontage* AttackMontage;

};

~~~

### ABAnimInstance.cpp
~~~cpp

#include "ABAnimInstance.h"

UABAnimInstance::UABAnimInstance() {
	...
	static ConstructorHelpers::FObjectFinder<UAnimMontage>ATTACK_MONTAGE(TEXT("/Game/Animations/SK_Mannequin_Skeleton_Montage.SK_Mannequin_Skeleton_Montage"));
	if (ATTACK_MONTAGE.Succeeded()) {
		AttackMontage = ATTACK_MONTAGE.Object;
	}
}

void UABAnimInstance::NativeUpdateAnimation(float DeltaSeconds) {
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (::IsValid(Pawn)) {
		CurrentPawnSpeed = Pawn->GetVelocity().Size();
		auto Character = Cast<ACharacter>(Pawn);
		if (Character) {
			IsInAir = Character->GetMovementComponent()->IsFalling();
		}
	}
}

void UABAnimInstance::PlayAttackMontage() {
	Montage_Play(AttackMontage, 1.0f);
}

void UABAnimInstance::AnimNotify_AttackHitCheck() {
	
	OnAttackHitCheck.Broadcast();
}

void UABAnimInstance::AnimNotify_NextAttackCheck() {
	ABLOG_S(Warning);
	OnNextAttackCheck.Broadcast();
}

void UABAnimInstance::JumpToAttackMontageSection(int32 NewSection) {
	ABCHECK(Montage_IsPlaying(AttackMontage));
	Montage_JumpToSection(GetAttackMontageSectionName(NewSection), AttackMontage);
}

FName UABAnimInstance::GetAttackMontageSectionName(int32 Section) {
	ABCHECK(FMath::IsWithinInclusive<int32>(Section, 1, 4), NAME_None);
	return FName(*FString::Printf(TEXT("Attack%d"), Section)); 
}

~~~

### MyActors.h
~~~cpp
#pragma once

#include "EngineMinimal.h"

...
#define ABCHECK(Expr, ...) {if(!(Expr)) {ABLOG(Error, TEXT("ASSERTION : %s"),TEXT("'"#Expr"'")); return __VA_ARGS__;}}

~~~

#### 학습내용 정리
1. 스테이트 머신을 사용하여 모든 공격에 대한 스테이트를 생성하고 트랜지션을 연결하여 구현할 수 있지만 스테이트를 계속 추가하면 스테이트 머신의 설계가 복잡해진다.

   언리얼 엔진은 스테이트 머신의 확장 없이 특정 상황에서 원하는 애니메이션을 발동시키는 애니메이션 몽타주라는 기능을 제공한다.
   
   몽타주는 섹션 단위로 애니메이션을 관리하며, 애니메이션들을 자르고 붙이는 기능을 제공한다.
   
   애니메이션 블루프린트에서 몽타주를 재생하기 위해 slot노드를 사용한다.
   
2. UPROPERTY에 설정하는 키워드인 EditAnywhere와 VisibleAnywhere에 있는 Anywher 키워드는 에디터와의 연동 방법에 따라 DefaultOnly와 InstanceOnly로 나뉜다.

   DefaultOnly는 클래스의 기본값을 담당하는 블루프린트 편집 화면에서만 보여진다.
   
   InstanceOnly는 인스턴스 속성을 보여주는 에디터 뷰포트에서만 보여진다.

3. 델리게이트(Delegate)는 넓은 의미로 특정 개체가 해야 할 로직을 다른 객체가 대신 처리할 수 있도록 만드는 설계의 개념을 의미한다.
   
   언리얼 엔진의 델리게이트는 A객체가 B객체에 작업 명령을 내릴 때 A의 함수를 B객체의 등록하고 명령을 내리면 B에서 명령을 실행하고 작업이 끝나면 A에게 알려주는 설계 방식을 의미.
   
  		 C++은 델리게이트 시스템을 지원하지 않기 때문에 언리얼 엔진에서 델리게이트를 사용하려면 별도로 구축한 델리게이트 프레임워크를 사용해야한다.
   
   		언리얼 엔진에서 델리게이트는 C++객체에만 사용할 수 있는 델리게이트와 C++, 블루프린트 객체가 모두 사용할 수 있는 델리게이트로 나뉜다.
   
   		블루프린트 오브젝트는 멤버 함수에 대한 정보를 저장하고 로딩하는 직렬화 메커니즘이 들어있기 때문에 일반 C++언어가 관리하는 방법으로 멤버함수를 관리할 수 없다.
   	
   		그래서 블루프린트와 관련된 C++함수는 모두 UFUNCTION 매크로를 사용해야 한다.
   
  	 	이렇게 블루프린트 객체와도 연동하는 델리게이트를 언리얼 엔진에서는 다이내믹 델리게이트라고 한다.
   		
4. 애님 인스턴스에는 애니메이션 몽타주 재생이 끝나면 발동하는 OnMontageEnded라는 델리게이트를 제공한다.
   
   OnMontageEnded 델리게이트는 블루프린트와 호환되는 성질 외에도 여러개의 함수를 받을 수 있어서 행동이 끝나면 등록된 모든 함수들에게 모두 알려준다.
   
   이러한 델리게이트를 멀티캐스트 델리게이트라고 한다.
   
   언리얼 엔진에서 델리게이트의 선언은 언리얼이 제공하는 메크로를 통해 정의되며, 이렇게 정의된 델리게이트의 형식을 시그니쳐라고 한다.
   
   DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMotageEndedMCDelegate, UAnimMontage*, Montage, bool, bInterrupted);
   
5. 언리얼 엔진의 애니메이션 시스템은 애니메이션을 재생하는 동안 특정 타이밍에 애님 인스턴스에게 신호를 보내는 애니메이션 노티파이라는 기능을 제공한다.

   노티파이가 호출되면 언리얼 엔진은 자동으로 애님 인스턴스 클래스의 'AnimNotify_노티파이명' 이라는 이름의 멤버 함수를 찾아서 호출한다.
   
   해당 멤버함수는 언리얼 런타임이 찾을 수 있도록 반드시 UFUNCTION 매크로가 지정돼야 한다.

   애니메이션 노티파이의 Tick Type은 Queued와 Branching Point가 있다.
   
   Queued는 비동기 방식으로 신호를 받게 돼서 적절한 타이밍에 신호를 받는 것을 놓치게 될 수 있다. Queued는 주로 타이밍에 민감하지 않은 사운드나 이펙트를 발생시킬 때 사용하는 것이 적합하다.
   
   Branching Point는 해당 프레임에 즉각적으로 반응한다.
   
6. Montage_JumpToSection함수를 사용하여 애니메이션 몽타주에서 애니메이션 섹션을 변경할 수 있다.
   		
		*섹션을 이동하는 코드를 올바르게 작성하여도 다음 원하는 섹션으로 이동하지 않는 오류가 생기면 애니메이션 몽타주의 블랜드 아웃 시간값을 적절히 조절하면 오류를 해결할 수 있다.
   
### 2023\-02\-14
학습내용: 교재 chapter9 실습
<br>

### ABCharacter.h
~~~cpp
...
public:	
	...
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)override;

	...

private:
	...

private:
	...
	
	UPROPERTY(VIsibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	float AttackRange;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	float AttackRadius;
};

~~~

### ABCharacter.h
~~~cpp
// Fill out your copyright notice in the Description page of Project Settings.


...
#include "DrawDebugHelpers.h"

// Sets default values
AABCharacter::AABCharacter()
{
 	...
	
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("ABCharacter"));
	AttackRange = 200.0f;
	AttackRadius = 50.0f;
}
void AABCharacter::PostInitializeComponents() {
	...
	
	ABAnim->OnAttackHitCheck.AddUObject(this, &AABCharacter::AttackCheck);
}

void AABCharacter::AttackCheck() {
	FHitResult HitResult;
	FCollisionQueryParams Params(NAME_None, false, this);
	bool bResult = GetWorld()->SweepSingleByChannel(
		HitResult,
		GetActorLocation(),
		GetActorLocation() + GetActorForwardVector() * AttackRange,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(AttackRadius),
		Params);
	
#if ENABLE_DRAW_DEBUG
	FVector TraceVec = GetActorForwardVector() * AttackRange;
	FVector Center = GetActorLocation() + TraceVec * 0.5f;
	float HalfHeight = AttackRange * 0.5f + AttackRadius;
	FQuat CapsuleRot = FRotationMatrix::MakeFromZ(TraceVec).ToQuat();
	FColor DrawColor = bResult ? FColor::Green : FColor::Red;
	float DebugLifeTime = 5.0f;

	DrawDebugCapsule(GetWorld(),
		Center,
		HalfHeight,
		AttackRadius,
		CapsuleRot,
		DrawColor,
		false,
		DebugLifeTime);
#endif
	if (bResult) {
		if (HitResult.GetActor()->IsValidLowLevel()) {
			ABLOG(Warning, TEXT("Hit Actor Name : %s"), *HitResult.GetActor()->GetName());
			
			FDamageEvent DamageEvent;
			HitResult.GetActor()->TakeDamage(50.0f, DamageEvent, GetController(), this);
		}
	}
}

float AABCharacter::TakeDamage(float DamageAmount, FDamageEvent const& FDamageEvent, AController* EventInstigator, AActor* DamageCauser) {
	float FinalDamage = Super::TakeDamage(DamageAmount,FDamageEvent,EventInstigator,DamageCauser);
	ABLOG(Warning, TEXT("Actor : %s took Damage : %f"), *GetName(), FinalDamage);
	if (FinalDamage > 0.0f) {
		ABAnim->SetDeadAnim();
		SetActorEnableCollision(false);
	}
	return FinalDamage;
}
~~~


#### 학습내용 정리
1. 언리얼 엔진에서 콜리전은 크게 세 가지 방법으로 제작할 수 있다.
	
		*스태틱메시 애셋: 스태틱메시 애셋에 콜리전 영역을 심는 방법.
		
		*기본도형 컴포넌트: 구체, 박스, 캡슐의 기본도형을 사용해 충돌 영역을 지정하는 방법.
		
		*피직스 애셋: 특정 상황에서 캐릭터의 각 관절이 흐느적거리는 RagDoll효과를 구현할 때 사용. 
		              캐릭터의 각 부위에 기본 도형으로 충돌 영역 설정.

2. 충돌체에는 반드시 하나의 콜리전 채널을 설정해야 하며 언리얼 엔진은 여덟개의 기본 콜리전 채널을 제공한다.
		
		*WorldStatic: 움직이지 않는 정적인 배경 엑터에 사용. 주로 스태틱메시 액터에 있는 스태틱메시 컴포넌트에 사용.
 		
		*WorldDynamic: 움직이는 액터에 사용하는 콜리전 채널. 블루프린트에 속한 스태틱메시 컴포넌트에 사용.
		
		*Pawn: 플레이어가 조종하는 물체에 주로 사용.
		
		*Visibility: 배경 물체가 시각적으로 보이는지 탐지하는 데 사용. 마우스로 물체를 선택하는 Picking기능을 구현할 때 사용.
		
		*Camera: 카메라 설정을 위해 카메라와 목표물 간에 장애물이 있는지 탐지.
		
		*PhysicsBody: 물리 시뮬레이션으로 움직이는 컴포넌트에 설정.

3. Collision Enabled 항목엔 다음과 같은 값이 있다.
		
		*Query: 두 물체의 충돌 영역이 서로 겹치는지 테스트 함. 
		        충돌 영역의 겹침을 감지하는 것을 언리얼 엔진에선 Overlap이라고 함.
		
		*Physics: 물리적인 시뮬레이션을 사용할 때 설정.
		
		*Query and Physics: 위의 두 기능을 모두 사용하는 설정.

4. 콜리전 채널과의 반응엔 3가지가 존재한다.
		
		*Ignore: 콜리전이 있어도 충돌을 무시.
		
		*Overlap: Ignore와 동일하게 물체가 뚫고 지나갈 수 있지만 이벤트를 발생시킨다.
		
		*Block: 물체가 뚫고 지나가지 못하도록 막는다.

5. 콜리전 채널은 다시 오브젝트 채널과 트레이스 채널로 나뉜다.
		
		*오브젝트 채널: 콜리전 영역에 지정하는 콜리전 채널.
		
		*트레이스 채널: 어떤 행동에 설정하는 콜리전 채널.
	
    언리얼 엔진은 게임에서 활용할 수 있도록 총 32개의 콜리전 채널을 제공한다.
    
    32개중 여덟 개는 언리얼 엔진이 기본으로 사용하고, 여섯 개는 엔진에서 다른 용도로 사용하도록 예약돼 있다. 이를 뺀 18개만 사용가능.
    

6. 트레이스 채널을 사용해 물리적 충돌 여부를 가리는 함수 중 하나로 SweepSingleByChannel이 있다. 물리는 월드의 기능이므로 GetWorld() 함수를 사용해 월드에게 명령을 내려야 한다.

   해당 함수는 기본 도형을 인자로 받은 후 시작 지점에서 끝 지점까지 쓸면서 해당 영역 내에 물리 판정이 일어났는지를 조사한다.
   
   해당 함수의 파라미터는 다음과 같다.
   		
		*HitResult: 물리적 충돌이 탐지된 경우 관련된 정보를 담을 구조체.
		
		*Start: 탐색 시작위치.
		
		*End: 탐색을 끝낼 위치.
		
		*Rot: 탐색에 사용할 도형의 회전.
		
		*TraceChannel: 물리 충돌 감지에 사용할 트레이스 채널 정보.
		
		*CollisionShape: 탐색에 사용할 기본 도형 정보.
		
		*Params: 탐색 방법에 대한 설정 값을 모아둔 구조체.
		 
		*ResponseParams: 탐색 반응을 설정하기 위한 구조체.
		

7. 		언리얼 실행 환경은 메모리에 떠있는 언리얼 오브젝트가 사용 중인지 아닌지를 주기적으로 검사하고, 사용하지 않는 물체를 발견하면 메모리에서 자동으로 제거한다.
		
		이를 가비지 컬렉션이라고 한다. 
		
		언리얼 오브젝트가 사용 중인지 여부는 다른 언리얼 오브젝트가 해당 오브젝트를 참조하는지로 판단하는데, FHitResult의 멤버 변수 Actor의 선언이 일반 참조로 선언 된다면 해당 함수에서의 참조로 인해 제거돼야 할 액터가 메모리에 그대로 남아있는 문제가 발생할 수 있다. 
		
		이런 문제를 방지하기 위해 FHitResult는 참조로부터 자유롭게 포인터 정보를 전달해주는 약 포인터(TWeakObjectPtr)방식으로 멤버 변수를 선헌했다. 
		
		약 포인터로 지정된 액터에 접근하려면 IsValid 함수(UE4)를 사용해 사용하려는 액터가 유효한지 먼저 점검하고 사용해야 한다.
		
8. 언리얼 엔진의 액터 클래스 AACtor는 TakeDamage라는 함수가 구현돼 있다.

    TakeDamage 함수는 총 네 개의 인자를 갖고 있다.
    		
		* DamageAmount: 전달할 대미지 세기
		* DamageEvent: 대미지 종류
		* EventInstigator: 공격 명령을 내린 가해자 (컨트롤러의 정보를 주어야 함)
		* DamageCauser: 대미지 전달을 위해 사용한 도구

### 2023\-02\-16
학습내용: 교재 chapter10 실습
<br>

### ABCharacter.h
~~~cpp

...

public:	
	
	...
	
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)override;
	
	...
	
	bool CanSetWeapon();
	void SetWeapon(class AABWeapon* NewWeapon);

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	class AABWeapon* CurrentWeapon;

...
~~~

### ABCharacter.cpp
~~~cpp
// Fill out your copyright notice in the Description page of Project Settings.


#include "ABCharacter.h"
#include "ABAnimInstance.h"
#include "DrawDebugHelpers.h"
#include "ABWeapon.h"

bool AABCharacter::CanSetWeapon() {
	return (nullptr == CurrentWeapon);
}

void AABCharacter::SetWeapon(AABWeapon* NewWeapon) {
	ABCHECK(nullptr != NewWeapon && nullptr == CurrentWeapon);
	FName WeaponSocket(TEXT("hand_rSocket"));
	if (nullptr != NewWeapon) {
		NewWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponSocket);
		NewWeapon->SetOwner(this);
		CurrentWeapon = NewWeapon;
	}
}
~~~

### ABWeapon.h
~~~cpp

#include "MyActors.h"
#include "GameFramework/Actor.h"
#include "ABWeapon.generated.h"

...

public:
	UPROPERTY(VisibleAnywhere, Category = Weapon)
	USkeletalMeshComponent* Weapon;
};

~~~

### ABWeapon.h
~~~cpp

#include "ABWeapon.h"

AABWeapon::AABWeapon()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WEAPON"));
	RootComponent = Weapon;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_WEAPON(TEXT("/Game/InfinityBladeWeapons/Weapons/Blade/Swords/Blade_BlackKnight/SK_Blade_BlackKnight.SK_Blade_BlackKnight"));
	if (SK_WEAPON.Succeeded()) {
		Weapon->SetSkeletalMesh(SK_WEAPON.Object);
	}

	Weapon->SetCollisionProfileName(TEXT("NoCollision"));

}

~~~

### ABItemBox.h
~~~cpp

#pragma once

#include "MyActors.h"
#include "GameFramework/Actor.h"
#include "ABItemBox.generated.h"

UCLASS()
class MYACTORS_API AABItemBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AABItemBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

public:	
	UPROPERTY(VisibleAnywhere, Category = Box)
	UBoxComponent* Trigger;

	UPROPERTY(VisibleAnywhere, Category = Box)
	UStaticMeshComponent* Box;

	UPROPERTY(VisibleAnywhere, Category = Effect)
	UParticleSystemComponent* Effect;

	UPROPERTY(EditAnywhere, Category = Box)
	TSubclassOf<class AABWeapon> WeaponItemClass;

private:
	UFUNCTION()
	void OnCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	void OnEffectFinished(class UParticleSystemComponent* PSystem);
};

~~~

### ABItemBox.cpp
~~~cpp
// Fill out your copyright notice in the Description page of Project Settings.

#include "ABItemBox.h"
#include "ABWeapon.h"
#include "ABCharacter.h"

// Sets default values
AABItemBox::AABItemBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("TRIGGER"));
	Box = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BOX"));
	Effect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("EFFECT"));

	RootComponent = Trigger;
	Box->SetupAttachment(RootComponent);
	Effect->SetupAttachment(RootComponent);

	Trigger->SetBoxExtent(FVector(40.0f, 42.0f, 18.0f));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>SM_BOX(TEXT("/Game/InfinityBladeGrassLands/Environments/Breakables/StaticMesh/Box/SM_Env_Breakables_Box1.SM_Env_Breakables_Box1"));
	
	if (SM_BOX.Succeeded()) {
		Box->SetStaticMesh(SM_BOX.Object);
	}

	static ConstructorHelpers::FObjectFinder<UParticleSystem>P_CHESTOPEN(TEXT("/Game/InfinityBladeGrassLands/Effects/FX_Treasure/Chest/P_TreasureChest_Open_Mesh.P_TreasureChest_Open_Mesh"));
	if (P_CHESTOPEN.Succeeded()) {
		Effect->SetTemplate(P_CHESTOPEN.Object);
		Effect->bAutoActivate = false;
	}

	Box->SetRelativeLocation(FVector(0.0f, -3.5f, -18.0f));

	Trigger->SetCollisionProfileName(TEXT("ItemBox"));
	Box->SetCollisionProfileName(TEXT("NoCollision"));

	WeaponItemClass = AABWeapon::StaticClass();
}

void AABItemBox::PostInitializeComponents() {
	Super::PostInitializeComponents();
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AABItemBox::OnCharacterOverlap);

}

void AABItemBox::OnCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	ABLOG_S(Warning);

	auto ABCharacter = Cast<AABCharacter>(OtherActor);
	ABCHECK(nullptr != ABCharacter);

	if (nullptr != ABCharacter && nullptr != WeaponItemClass) {
		if (ABCharacter->CanSetWeapon()) {
			auto NewWeapon = GetWorld()->SpawnActor<AABWeapon>(WeaponItemClass, FVector::ZeroVector, FRotator::ZeroRotator);
			ABCharacter->SetWeapon(NewWeapon);
			Effect->Activate(true);
			Box->SetHiddenInGame(true, true);
			SetActorEnableCollision(false);
			Effect->OnSystemFinished.AddDynamic(this, &AABItemBox::OnEffectFinished);
		}
		else {
			ABLOG(Warning, TEXT("%s can't equip weapon currently."), *ABCharacter->GetName());
		}
	}
}

void AABItemBox::OnEffectFinished(UParticleSystemComponent* PSystem) {
	Destroy();
}
~~~

#### 학습내용 정리
1. 캐릭터의 무기를 캐릭터의 트랜스폼에 배치하지 않고 Mesh에 배치해야 무기가 캐릭터의 애니메이션을 따라 움직인다.
   
   언리얼 엔진은 캐릭터에 무기나 액세서리를 부착하기위한 용도로 소켓이라는 시스템을 제공한다.
  
   코드로 무기를 장착할 때 스켈레탈 메시 컴포넌트에 무기를 로딩하고 SetupAttachment 함수에 소켓 이름을 인자로 넘겨주면 소켓 위치를 기준으로 트랜스폼이 자동으로 설정된다.
   
2. 박스 컴포넌트에는 Overlap 이벤트를 처리할 수 있게 OnComponentBeginOverlap이라는 이름의 델리게이트가 선언돼 있다.

   다이나믹 델리게이트는 UFUNCTION 함수를 사용해야 하므로 람다식으로 표현한 함수는 바인딩할 수 없다.
   
3. 클래스 정보를 저장하는 변수를 선언할 때 UClass의 포인터를 사용할 수 있지만, 이를 사용하면 현재 프로젝트에 사용하는 모든 언리얼 오브젝트의 선언이 보이게 된다.

   언리얼 엔진은 특정 클래스와 상속받은 클래스들로 목록을 한정하도록 TSubclassof라는 키워드를 제공한다.
   

### 2023\-02\-18
학습내용: 교재 chapter11 실습
<br>

### ABGameInstance.h
~~~cpp

#pragma once

#include "MyActors.h"
#include "Engine/DataTable.h"
#include "Engine/GameInstance.h"
#include "ABGameInstance.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FABCharacterData : public FTableRowBase {
	GENERATED_BODY()

public:
	FABCharacterData() : Level(1), MaxHP(100.0f), Attack(10.0f), DropExp(10), NextExp(30){}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float MaxHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float Attack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 DropExp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 NextExp;

};

UCLASS()
class MYACTORS_API UABGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UABGameInstance();

	virtual void Init() override;
	FABCharacterData* GetABCharacterData(int32 Level);

private:
	UPROPERTY()
	class UDataTable* ABCharacterTable;
};

~~~

### ABGameInstance.cpp
~~~cpp

#include "ABGameInstance.h"

UABGameInstance::UABGameInstance() {
	FString CharacterDataPath = TEXT("/Game/GameData/ABCharacterData.ABCharacterData");

	static ConstructorHelpers::FObjectFinder<UDataTable>DT_ABCHARACTER(*CharacterDataPath);
	ABCHECK(DT_ABCHARACTER.Succeeded());
	ABCharacterTable = DT_ABCHARACTER.Object;
	ABCHECK(ABCharacterTable->GetRowMap().Num() > 0);
}

void UABGameInstance::Init() {
	Super::Init();
	ABLOG(Warning, TEXT("DropExp of Level 20 ABCharacter : %d"), GetABCharacterData(20)->DropExp);

}

FABCharacterData* UABGameInstance::GetABCharacterData(int32 Level) {
	return ABCharacterTable->FindRow<FABCharacterData>(*FString::FromInt(Level), TEXT(""));
}

~~~

### ABCharacterStatComponent.h
~~~cpp

#pragma once

#include "MyActors.h"
#include "Components/ActorComponent.h"
#include "ABCharacterStatComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnHPIsZeroDelegate);
DECLARE_MULTICAST_DELEGATE(FOnHPChangedDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYACTORS_API UABCharacterStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UABCharacterStatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void InitializeComponent() override;

public:
	void SetNewLevel(int32 NewLevel);
	void SetDamage(float NewDamage);
	void SetHP(float NewHP);
	float GetAttack();
	float GetHPRatio();

	FOnHPIsZeroDelegate OnHPIsZero;
	FOnHPChangedDelegate OnHPChanged;
private:
	struct FABCharacterData* CurrentStatData = nullptr;

	UPROPERTY(EditInstanceOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
	int32 Level;

	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
	float CurrentHP;

};

~~~

### ABCharacterStatComponent.cpp
~~~cpp

#include "ABCharacterStatComponent.h"
#include "ABGameInstance.h"

// Sets default values for this component's properties
UABCharacterStatComponent::UABCharacterStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	bWantsInitializeComponent = true;
	
	Level = 1;
}

void UABCharacterStatComponent::InitializeComponent() {
	Super::InitializeComponent();
	SetNewLevel(Level);
}

void UABCharacterStatComponent::SetNewLevel(int32 NewLevel) {
	auto ABGameInstance = Cast<UABGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	ABCHECK(nullptr != ABGameInstance);
	CurrentStatData = ABGameInstance->GetABCharacterData(NewLevel);
	if (nullptr != CurrentStatData) {
		Level = NewLevel;
		SetHP(CurrentStatData->MaxHP);
		
	}
	else {
		ABLOG(Error, TEXT("Level (%d) data dosen't exist"), NewLevel);
	}
}

void UABCharacterStatComponent::SetDamage(float NewDamage) {
	ABCHECK(nullptr != CurrentStatData);
	SetHP(FMath::Clamp<float>(CurrentHP - NewDamage, 0.0f, CurrentStatData->MaxHP));
}

float UABCharacterStatComponent::GetAttack() {
	ABCHECK(nullptr != CurrentStatData, 0.0f);
	return CurrentStatData->Attack;
}

void UABCharacterStatComponent::SetHP(float NewHP) {
	CurrentHP = NewHP;
	OnHPChanged.Broadcast();
	if (CurrentHP < KINDA_SMALL_NUMBER) {
		CurrentHP = 0.0f;
		OnHPIsZero.Broadcast();
	}
}

float UABCharacterStatComponent::GetHPRatio() {
	ABCHECK(nullptr != CurrentStatData, 0.0f);

	return(CurrentStatData->MaxHP < KINDA_SMALL_NUMBER) ? 0.0f : (CurrentHP / CurrentStatData->MaxHP);
}

~~~

### ABCharacterWidget.h
~~~cpp

#pragma once

#include "MyActors.h"
#include "Blueprint/UserWidget.h"
#include "ABCharacterWidget.generated.h"

/**
 * 
 */
UCLASS()
class MYACTORS_API UABCharacterWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void BindCharacterStat(class UABCharacterStatComponent* NewCharacterStat);

protected:
	virtual void NativeConstruct() override;
	void UpdateHPWidget();

private:
	TWeakObjectPtr<class UABCharacterStatComponent> CurrentCharacterStat;

	UPROPERTY()
	class UProgressBar* HPProgressBar;
};

~~~

### ABCharacterWidget.h
~~~cpp

#include "ABCharacterWidget.h"
#include "ABCharacterStatComponent.h"
#include "Components/ProgressBar.h"

void UABCharacterWidget::BindCharacterStat(UABCharacterStatComponent* NewCharacterStat) {
	ABCHECK(nullptr != NewCharacterStat);

	CurrentCharacterStat = NewCharacterStat;
	NewCharacterStat->OnHPChanged.AddUObject(this, &UABCharacterWidget::UpdateHPWidget);
}

void UABCharacterWidget::NativeConstruct() {
	Super::NativeConstruct();
	HPProgressBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("PB_HPBar")));
	ABCHECK(nullptr != HPProgressBar);
	UpdateHPWidget();
}

void UABCharacterWidget::UpdateHPWidget() {
	if (CurrentCharacterStat.IsValid()) {
		if (nullptr != HPProgressBar) {
			HPProgressBar->SetPercent(CurrentCharacterStat->GetHPRatio());
		}
	}
}

~~~

### ABCharacterWidget.cpp
~~~cpp

#include "ABCharacterWidget.h"
#include "ABCharacterStatComponent.h"
#include "Components/ProgressBar.h"

void UABCharacterWidget::BindCharacterStat(UABCharacterStatComponent* NewCharacterStat) {
	ABCHECK(nullptr != NewCharacterStat);

	CurrentCharacterStat = NewCharacterStat;
	NewCharacterStat->OnHPChanged.AddUObject(this, &UABCharacterWidget::UpdateHPWidget);
}

void UABCharacterWidget::NativeConstruct() {
	Super::NativeConstruct();
	HPProgressBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("PB_HPBar")));
	ABCHECK(nullptr != HPProgressBar);
	UpdateHPWidget();
}

void UABCharacterWidget::UpdateHPWidget() {
	if (CurrentCharacterStat.IsValid()) {
		if (nullptr != HPProgressBar) {
			HPProgressBar->SetPercent(CurrentCharacterStat->GetHPRatio());
		}
	}
}

~~~

### ABCharacter.h
~~~cpp
...
public:	
	...
	
	UPROPERTY(VisibleAnywhere, Category = Stat)
	class UABCharacterStatComponent* CharacterStat;

	UPROPERTY(VisibleAnywhere, Category = UI)
	class UWidgetComponent* HPBarWidget;
~~~
...

### ABCharacter.cpp
~~~cpp

#include "Components/WidgetComponent.h"
#include "ABCharacterWidget.h"

AABCharacter::AABCharacter()
{
 	...
	
	CharacterStat = CreateDefaultSubobject<UABCharacterStatComponent>(TEXT("CHARACTERSTAT"));

	HPBarWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HPBARWIDGET"));
	HPBarWidget->SetupAttachment(GetMesh());

	HPBarWidget->SetRelativeLocation(FVector(0.0f, 0.0f, 180.0f));
	HPBarWidget->SetWidgetSpace(EWidgetSpace::Screen);
	static ConstructorHelpers::FClassFinder<UUserWidget>UI_HUD(TEXT("/Game/UI/UI_HPBar.UI_HPBar_C"));
	if (UI_HUD.Succeeded()) {
		HPBarWidget->SetWidgetClass(UI_HUD.Class);
		HPBarWidget->SetDrawSize(FVector2D(150.0f, 50.0f));
	}
}

void AABCharacter::PostInitializeComponents() {

	...
	
	CharacterStat->OnHPIsZero.AddLambda([this]() -> void {
		ABLOG(Warning, TEXT("OnHPIsZero"));
		ABAnim->SetDeadAnim();
		SetActorEnableCollision(false);
	});

	HPBarWidget->InitWidget();
	auto CharacterWidget = Cast<UABCharacterWidget>(HPBarWidget->GetUserWidgetObject());
	if (nullptr != CharacterWidget) {
		CharacterWidget->BindCharacterStat(CharacterStat);
	}

}

...

float AABCharacter::TakeDamage(float DamageAmount, FDamageEvent const& FDamageEvent, AController* EventInstigator, AActor* DamageCauser) {
	float FinalDamage = Super::TakeDamage(DamageAmount,FDamageEvent,EventInstigator,DamageCauser);
	ABLOG(Warning, TEXT("Actor : %s took Damage : %f"), *GetName(), FinalDamage);
	CharacterStat->SetDamage(FinalDamage);
	return FinalDamage;
}

...
~~~

#### 학습내용 정리
1. 게임 앱이 초기화 되면 언리얼 엔진은 GameInstance의 Init함수를 호출한다.
   
   게임을 시작하면 게임 앱을 초기화하고(UGameInstance::Init) 월드를 생성 후 월드에 레벨을 로딩해 스테이지를 생성하고 나면(AActor::PostInitializeComponents) 플레이어가 로그인해 준비를 마쳐야(AGameMode::PostLogin) 게임이 시작된다(AGameMode::StartPlay, AActor::BeginPlay).
   
2. 언리얼 엔진은 CSV파일에 행과 열로 구성된 테이블 데이터를 불러오는 기능을 제공한다.

   CSV파일을 언리얼 엔진에서 불러들이기 위해 테이블 데이터의 각 열의 이름과 유형이 동일한 구조체를 선언해야 한다.
   
   언리얼 엔진에서 제공하는 FTableRowBase 구조체를 상속받아 새로운 구조체를 GameInstance 헤더에 선언한다.
   
   구조체를 생성할 때 언리얼이 지정한 규칙에 따라줘야 에디터 인터페이스에서 연동해 사용할 수 있다.
   
   USTRUCT 매크로를 구조체 선언 윗줄에 넣고 구조체 내부에는 GENERATED_BODY()매크로를 선언한다.
   
   구조체의 골격을 완성하면 CSV 파일의 각 열의 이름과 동일한 멤버 변수를 타입에 맞춰 선언한다.
 
3. 액터 컴포넌트 클래스는 액터의 PostInitializeComponents에 대응하는 InitializeComponent 함수가 존재한다. 이 함수는 액터의 PostInitializeComponents 함수가 호출되기 바로 전에 호출된다.

   InitializeComponent 함수가 호출되려면 생성자에서 bWantsInitializeComponent 값을 true로 설정해야 한다.
   
4. 언리얼 오브젝트에는 직렬화(Serialization)기능이 있어서 오브젝트의 UPROPERTY 속성을 저장하고 로딩할 수 있다. 하지만 UPROPERTY 매크로에 Transient 키워드를 추가하면 해당 속성을 직렬화에서 제외시킬 수 있다.  

5. 언리얼 엔진은 엑터에 UI위젯을 부착할 수 있도록 UWidgetComponent라는 클래스를 제공한다.
   
   UWidgetComponent 클래스를 사용하려면 UI에 관련된 엔진 모듈을 지정해줘야 한다. 그렇지 않을 경우 컴파일이 되지 않는다.
   
   모듈의 Build,cs 파일에서 프로젝트에서 현재 사용하는 언리얼 엔진의 모듈을 확인할 수 있다.
   
   언리얼 에디터가 자동으로 생성하는 개발 환경에 의해 핵심적으로 사용하는 몇 개의 모듈만 개발 환경에 지정해 사용하고 있으며, 그 모듈은 Core, CoreUObject, Engine, InputCore이다.
   
   UWidgetComponent 클래스를 사용하기 위해 PublicDependencyModuleName.AddRange에 UMG를 추가해야 한다.
   
   모듈 설정을 완료하면 언리얼 빌드 툴에 의해 UMG모듈의 헤더파일 경로도 별도의 설정없이 바로 사용할 수 있도록 기본 경로로 설정된다.
   
6. UI 시스템이 준비되면 NativeConstructor 함수가 호출되는데, UI 생성은 플레이어 컨트롤러릐 BeginPlayer에서 호출되므로 BeginPlay 전에 호출된 PostInitializeComponents함수에서 발생한 명령은 UI에 반영되지 않는다.

### 2023\-02\-21
학습내용: 교재 chapter12 실습
<br>

### ABAIController.h
~~~cpp

#pragma once

#include "MyActors.h"
#include "AIController.h"
#include "ABAIController.generated.h"

/**
 * 
 */
UCLASS()
class MYACTORS_API AABAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AABAIController();
	
	virtual void OnPossess(APawn* InPawn) override;

	static const FName HomePosKey;
	static const FName PatrolPosKey;
	static const FName TargetKey;

private:
	UPROPERTY()
	class UBehaviorTree* BTAsset;

	UPROPERTY()
	class UBlackboardData* BBAsset;
};

~~~

### ABAIController.cpp
~~~cpp

#include "ABAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

const FName AABAIController::HomePosKey(TEXT("HomePos"));
const FName AABAIController::PatrolPosKey(TEXT("PatrolPos"));
const FName AABAIController::TargetKey(TEXT("Target"));

AABAIController::AABAIController() {
	static ConstructorHelpers::FObjectFinder<UBlackboardData>BBObject(TEXT("/Game/AI/BB_ABCharacter.BB_ABCharacter"));
	if (BBObject.Succeeded()) {
		BBAsset = BBObject.Object;
	}

	static ConstructorHelpers::FObjectFinder<UBehaviorTree>BTObject(TEXT("/Game/AI/BT_ABCharacter.BT_ABCharacter"));
	if (BTObject.Succeeded()) {
		BTAsset = BTObject.Object;
	}
}

void AABAIController::OnPossess(APawn* InPawn) {
	Super::OnPossess(InPawn);
	UBlackboardComponent* BlackboardComp = Blackboard.Get();
	if (UseBlackboard(BBAsset, BlackboardComp)) {
		BlackboardComp->SetValueAsVector(HomePosKey, InPawn->GetActorLocation());
		if (!RunBehaviorTree(BTAsset)) {
			ABLOG(Error, TEXT("AIController couldn't run behavior tree!"));
		}
	}
}

~~~

### BTService_Detect.h
~~~cpp

#pragma once

#include "MyActors.h"
#include "BehaviorTree/BTService.h"
#include "BTService_Detect.generated.h"

/**
 * 
 */
UCLASS()
class MYACTORS_API UBTService_Detect : public UBTService
{
	GENERATED_BODY()
	
public:
	UBTService_Detect();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};

~~~

### BTService_Detect.cpp
~~~cpp

#include "BTService_Detect.h"
#include "ABAIController.h"
#include "ABCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"

UBTService_Detect::UBTService_Detect() {
	NodeName = TEXT("Detect");
	Interval = 1.0f;
}

void UBTService_Detect::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) {
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	
	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn) return;

	UWorld* World = ControllingPawn->GetWorld();
	FVector Center = ControllingPawn->GetActorLocation();
	float DetectRadius = 600.0f;

	if (nullptr == World) return;
	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams CollisionQueryParam(NAME_None, false, ControllingPawn);
	bool bResult = World->OverlapMultiByChannel(
		OverlapResults,
		Center,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(DetectRadius),
		CollisionQueryParam
	);

	if (bResult) {
		for (auto OverlapResult : OverlapResults) {
			AABCharacter* ABCharacter = Cast<AABCharacter>(OverlapResult.GetActor());
			if (ABCharacter && ABCharacter->GetController()->IsPlayerController()) {
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(AABAIController::TargetKey, ABCharacter);
				DrawDebugSphere(World, Center, DetectRadius, 16, FColor::Green, false, 0.2f);
				DrawDebugPoint(World, ABCharacter->GetActorLocation(), 10.0f, FColor::Blue, false, 0.2f);
				DrawDebugLine(World, ControllingPawn->GetActorLocation(), ABCharacter->GetActorLocation(), FColor::Blue, false, 0.2f);
				return;
			}
			else {
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(AABAIController::TargetKey, nullptr);
			}
		}
	}

	DrawDebugSphere(World, Center, DetectRadius, 16, FColor::Red, false, 0.2f);

 }

~~~

### BTTask_Attack.h
~~~cpp

#pragma once

#include "MyActors.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Attack.generated.h"

/**
 * 
 */
UCLASS()
class MYACTORS_API UBTTask_Attack : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTask_Attack();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

private:
	bool IsAttacking = false;

};

~~~

### BTTask_Attack.h
~~~cpp

#include "BTTask_Attack.h"
#include "ABAIController.h"
#include "ABCharacter.h"

UBTTask_Attack::UBTTask_Attack() {
	bNotifyTick = true;
	IsAttacking = false;
}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto ABCharacter = Cast<AABCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == ABCharacter) return EBTNodeResult::Failed;

	ABCharacter->Attack();
	IsAttacking = true;
	ABCharacter->OnAttackEnd.AddLambda([this]() -> void {
		IsAttacking = false;
	});

	return EBTNodeResult::InProgress;
}

void UBTTask_Attack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) {
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
	if (!IsAttacking) {
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
}

~~~

### BTTask_FindPatrolPos.h
~~~cpp

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_FindPatrolPos.generated.h"

/**
 * 
 */
UCLASS()
class MYACTORS_API UBTTask_FindPatrolPos : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTask_FindPatrolPos();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8 * NodeMemory) override;
};

~~~

### BTTask_FindPatrolPos.cpp
~~~cpp

#include "BTTask_FindPatrolPos.h"
#include "ABAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"

UBTTask_FindPatrolPos::UBTTask_FindPatrolPos() {
	NodeName = TEXT("FindPatrolPos");
}

EBTNodeResult::Type UBTTask_FindPatrolPos::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn) return EBTNodeResult::Failed;

	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(ControllingPawn->GetWorld());
	if (nullptr == NavSystem) return EBTNodeResult::Failed;

	FVector Origin = OwnerComp.GetBlackboardComponent()->GetValueAsVector(AABAIController::HomePosKey);
	FNavLocation NextPatrol;
	if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.0f, NextPatrol)) {
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(AABAIController::PatrolPosKey, NextPatrol.Location);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}

~~~

### BTTask_TurnToTarget.h
~~~cpp

#pragma once

#include "MyActors.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_TurnToTarget.generated.h"

/**
 * 
 */
UCLASS()
class MYACTORS_API UBTTask_TurnToTarget : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTask_TurnToTarget();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};

~~~

### BTTask_TurnToTarget.cpp
~~~cpp

#include "BTTask_TurnToTarget.h"
#include "ABAIController.h"
#include "ABCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_TurnToTarget::UBTTask_TurnToTarget() {
	NodeName = TEXT("Turn");
}

EBTNodeResult::Type UBTTask_TurnToTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);
	auto ABCharacter = Cast<AABCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == ABCharacter) return EBTNodeResult::Failed;

	auto Target = Cast<AABCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(AABAIController::TargetKey));
	if (nullptr == Target) return EBTNodeResult::Failed;

	FVector LookVector = Target->GetActorLocation() - ABCharacter->GetActorLocation();
	LookVector.Z = 0.0f;
	FRotator TargetRot = FRotationMatrix::MakeFromX(LookVector).Rotator();
	ABCharacter->SetActorRotation(FMath::RInterpTo(ABCharacter->GetActorRotation(), TargetRot, GetWorld()->GetDeltaSeconds(), 2.0f));

	return EBTNodeResult::Succeeded;
}

~~~

### BTDecorator_IsInAttackRange.h
~~~cpp

#pragma once

#include "MyActors.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_IsInAttackRange.generated.h"

/**
 * 
 */
UCLASS()
class MYACTORS_API UBTDecorator_IsInAttackRange : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UBTDecorator_IsInAttackRange();

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};

~~~

### BTDecorator_IsInAttackRange.cpp
~~~cpp

#include "BTDecorator_IsInAttackRange.h"
#include "ABAIController.h"
#include "ABCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTDecorator_IsInAttackRange::UBTDecorator_IsInAttackRange() {
	NodeName = TEXT("CanAttack");
}

bool UBTDecorator_IsInAttackRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const {
	bool bResult = Super::CalculateRawConditionValue(OwnerComp,NodeMemory);

	auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn) return false;

	auto Target = Cast<AABCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(AABAIController::TargetKey));
	if (nullptr == Target) return false;

	bResult = (Target->GetDistanceTo(ControllingPawn) <= 200.0f);
	return bResult;
}

~~~

### ABCharacter.h
~~~cpp

protected:
	
	...

	enum class EControlMode {

		GTA,
		DIABLO,
		NPC
	};
	
	...
	
public:	

	...
	
	virtual void PossessedBy(AController* NewController)override;
	
	...
	
	void Attack();
	FOnAttackEndDelegate OnAttackEnd;

~~~

### ABCharacter.cpp
~~~cpp

...

#include "ABAIController.h"


AABCharacter::AABCharacter()
{
 	...
	
	AIControllerClass = AABAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

void AABCharacter::SetControlMode(EControlMode NewControlMode) {
	
	CurrentControlMode = NewControlMode;
	switch (CurrentControlMode)
	{
	
	...

	case EControlMode::NPC:
		bUseControllerRotationYaw = false;
		GetCharacterMovement()->bUseControllerDesiredRotation = false;
		GetCharacterMovement()->bOrientRotationToMovement = true;
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 480.0f, 0.0f);
		break;
	default:
		break;
	}
	
}

void AABCharacter::PossessedBy(AController* NewController) {
	Super::PossessedBy(NewController);
	if (IsPlayerControlled()) {
		SetControlMode(EControlMode::DIABLO);
		GetCharacterMovement()->MaxWalkSpeed = 600.0f;
	}
	else {
		SetControlMode(EControlMode::NPC);
		GetCharacterMovement()->MaxWalkSpeed = 300.0f;
	}
}

~~~

#### 학습내용 정리
1. 언리얼 엔진은 컴퓨터가 인공지능으로 NPC를 제어하도록 AI컨트롤러를 제공한다.
   
   내비게이션 메시를 레벨에 배치하여 NPC가 움직일 수 있는 영역을 정해준다.
   
   언리얼 엔진 4.20버전 부터 내비게이션 시스템 구조가 변경되어 NavigationSystem 모듈을 추가해야하고, NavigationSystem클래스가 NavigationSystemV1으로 변경됐다.
   
2. AI 컨트롤러에 특정 로직을 부여해 스스로 움직이는 NPC의 행동을 제작할 수 있지만, 좀더 복잡한 NPC 행동 패턴을 구현하려면 체계적인 모델에서 설계하는 것이 바람직하다.

   언리얼 엔진은 비헤이비어 트리 모델과 이를 편집하는 에디터를 제공한다.
   
   비헤이비어 트리를 제작하기 위해서는 비헤이비어 트이롸 블랙보드 애셋을 생성해야 한다.
   		
		* 블랙보드: 블랙보드는 인공지능의 판단에 사용하는 데이터 집합을 의미. NPC의 의사 결정은 블랙보드에 있는 데이터 기반으로 진행.
		
		* 비헤이비어 트리: 블랙보드 데이터에 기반해 설계한 비헤이비어 트리의 정보를 저장한 애셋.
    
3. 비헤이비어 트리에서 태스크는 독립적으로 실행될 수 없고 반드시 Composite 노드를 거쳐 실행돼야 한다.
   
   Composite 노드는 대표적으로 Selector와 Sequence가 있다.
   
   비헤이비어 트리는 태스크를 실행할 때 태스크 클래스의 ExecuteTask라는 멤버 함수를 실행한다. ExecuteTask 함수는 다음의 셋 중 하나의 값을 반환해야 한다. 
       
       * Aborted: 태스크 실행 중에 중단됐다. 결과적으로 실패했다.
       
       * Failed: 태스크를 수행했지만 실패했다.
       
       * Succeeded: 태스크를 성공적으로 수행했다.
       
       * InProgress: 태스크를 계속 수행하고 있다.
       
   ExecuteTask의 결과 값을 InProgress로 반환하면 나중에 태스크가 끝났다고 알려줘야 한다. 이를 알려주는 함수가 FinishLatentTask 함수다.
   
   이 함수를 호출해주지 않으면 비헤이비어 트리 시스템은 현재 태스크에 계속 머물게 된다.
   
       
4. 언리얼 엔진은 서비스 노드를 제공한다. 서비스 노드는 독립적으로 동작하지 않고 Composite 노드에 부착되는 노드다.

   또한 서비스 노드는 해당 Composite에 속한 태스크들이 실행되는 동안 반복적인 작업을 실행하는 데 적합하다.
   
   서비스 노드는 자신이 속한 Composite 노드가 활성화 됭 경우 주기적으로 TickNode 함수를 호출한다.
   
5. 언리얼 엔진은 블랙보드의 값을 기반으로 특정 Coomposite 노드의 실행 여부를 결정하는 데코레이터 노드를 제공한다. 
   
   데코레이터 클래스는 CalculateRawConditionValue 함수를 상속받아 원하는 조건이 달성됐는지 파악하도록 설계됐다.
   
   이 함수는 const로 선언돼 데코레이터 클래스의 멤버 변수 값은 변경 불가능하다.

### 2023\-02\-27
학습내용: 교재 chapter13 실습
<br>

### ABCharacterSetting.h
~~~cpp

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ABCharacterSetting.generated.h"

/**
 * 
 */
UCLASS(config = ArenaBattle)
class ARENABATTLESETTING_API UABCharacterSetting : public UObject
{
	GENERATED_BODY()
	
public:
	UABCharacterSetting();

	UPROPERTY(config)
	TArray<FSoftObjectPath>CharacterAssets;

~~~

### ABGameInstance.h
~~~cpp

#pragma once

#include "MyActors.h"
#include "Engine/DataTable.h"
#include "Engine/GameInstance.h"
#include "Engine/StreamableManager.h"
#include "ABGameInstance.generated.h"

...

UCLASS()
class MYACTORS_API UABGameInstance : public UGameInstance
{
	...

public:

	...

	FStreamableManager StreamableManager;

...

~~~

### ABCharacter.h
~~~cpp

...

private:

	...
	
	void OnAssetLoadCompleted();

private:

	...
	
	FSoftObjectPath CharacterAssetToLoad = FSoftObjectPath(nullptr);
	TSharedPtr<struct FStreamableHandle> AssetStreamingHandle;
};

~~~

### ABCharacter.h
~~~cpp
#include "ABGameInstance.h"

...
void AABCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (!IsPlayerControlled()) {
		auto DefaultSetting = GetDefault<UABCharacterSetting>();
		int32 RandIndex = FMath::RandRange(0, DefaultSetting->CharacterAssets.Num() - 1);
		CharacterAssetToLoad = DefaultSetting->CharacterAssets[RandIndex];

		auto ABGameInstance = Cast<UABGameInstance>(GetGameInstance());
		if (nullptr != ABGameInstance) {
			AssetStreamingHandle = ABGameInstance->StreamableManager.RequestAsyncLoad(CharacterAssetToLoad, FStreamableDelegate::CreateUObject(this, &AABCharacter::OnAssetLoadCompleted));
		}
	}
}

...

void AABCharacter::OnAssetLoadCompleted() {
	AssetStreamingHandle->ReleaseHandle();
	TSoftObjectPtr<USkeletalMesh>LoadedAssetPath(CharacterAssetToLoad);
	if (LoadedAssetPath.IsValid()) {
		GetMesh()->SetSkeletalMesh(LoadedAssetPath.Get());
	}
}

~~~

### ABSection.h
~~~cpp

#pragma once

#include "MyActors.h"
#include "GameFramework/Actor.h"
#include "ABSection.generated.h"

UCLASS()
class MYACTORS_API AABSection : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AABSection();
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	enum class ESectionState :uint8 {
		READY = 0,
		BATTLE,
		COMPLETE
	};

	void SetState(ESectionState NewState);
	ESectionState CurrentState = ESectionState::READY;
	
	void OperateGates(bool bOpen = true);

	UFUNCTION()
	void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	UFUNCTION()
	void OnGateTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void OnNPCSpawn();
private:
	UPROPERTY(VisibleAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
	TArray<UStaticMeshComponent*>GateMeshes;

	UPROPERTY(VisibleAnywhere, Category = Trigger, Meta = (AllowPrivateAccess = true))
	TArray<UBoxComponent*> GateTriggers;

	UPROPERTY(VisibleAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, Category = Trigger, Meta = (AllowPrivateAccess = true))
	UBoxComponent* Trigger;

	UPROPERTY(EditAnywhere, Category = State, Meta = (AllowPrivateAccess = true))
	bool bNoBattle;

	UPROPERTY(EditAnywhere, Category = Spawn, Meta = (AllowPrivateAccess = true))
	float EnemySpawnTime;

	UPROPERTY(EditAnywhere, Category = Spawn, Meta = (AllowPrivateAccess = true))
	float ItemBoxSpawnTime;

	FTimerHandle SpawnNPCTimerHandle = {};
	FTimerHandle SpawnItemBoxTimerHandle = { };
};

~~~

### ABSection.h
~~~cpp

#include "ABSection.h"
#include "ABCharacter.h"
#include "ABItemBox.h"

// Sets default values
AABSection::AABSection()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	RootComponent = Mesh;

	FString AssetPath = TEXT("/Game/Book/StaticMesh/SM_SQUARE.SM_SQUARE");
	static ConstructorHelpers::FObjectFinder<UStaticMesh>SM_SQUARE(*AssetPath);
	if (SM_SQUARE.Succeeded()) {
		Mesh->SetStaticMesh(SM_SQUARE.Object);
	}
	else {
		ABLOG(Error, TEXT("Failed to load staticmesh asset. : %s"), *AssetPath);
	}

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("TRIGGER"));
	Trigger->SetBoxExtent(FVector(775.0f, 775.0f, 300.0f));
	Trigger->SetupAttachment(RootComponent);
	Trigger->SetRelativeLocation(FVector(0.0f, 0.0f, 250.0f));
	Trigger->SetCollisionProfileName(TEXT("ABTrigger"));
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AABSection::OnTriggerBeginOverlap);

	FString GateAssetPath = TEXT("/Game/Book/StaticMesh/SM_GATE.SM_GATE");
	static ConstructorHelpers::FObjectFinder<UStaticMesh>SM_GATE(*GateAssetPath);
	if (!SM_GATE.Succeeded()) {
		ABLOG(Error, TEXT("Failed to load staticmesh asset. : %s"), *GateAssetPath);
	}

	static FName GateSockets[] = { {TEXT("+XGate")}, {TEXT("-XGate")}, {TEXT("+YGate")}, {TEXT("-YGate")} };
	for (FName GateSocket : GateSockets) {
		ABCHECK(Mesh->DoesSocketExist(GateSocket));
		UStaticMeshComponent* NewGate = CreateDefaultSubobject<UStaticMeshComponent>(*GateSocket.ToString());
		NewGate->SetStaticMesh(SM_GATE.Object);
		NewGate->SetupAttachment(RootComponent, GateSocket);
		NewGate->SetRelativeLocation(FVector(0.0f, -80.5f, 0.0f));
		GateMeshes.Add(NewGate);
		UBoxComponent* NewGateTrigger = CreateDefaultSubobject<UBoxComponent>(*GateSocket.ToString().Append(TEXT("Trigger")));
		NewGateTrigger->SetBoxExtent(FVector(100.0f, 100.0f, 300.0f));
		NewGateTrigger->SetupAttachment(RootComponent, GateSocket);
		NewGateTrigger->SetRelativeLocation(FVector(70.0f, 0.0f, 250.0f));
		NewGateTrigger->SetCollisionProfileName(TEXT("ABTrigger"));
		GateTriggers.Add(NewGateTrigger);

		NewGateTrigger->OnComponentBeginOverlap.AddDynamic(this, &AABSection::OnGateTriggerBeginOverlap);
		NewGateTrigger->ComponentTags.Add(GateSocket);
	}

	bNoBattle = false;

	EnemySpawnTime = 2.0f;
	ItemBoxSpawnTime = 5.0f;
}

// Called when the game starts or when spawned
void AABSection::BeginPlay()
{
	Super::BeginPlay();
	SetState(bNoBattle ? ESectionState::COMPLETE : ESectionState::READY);
}

void AABSection::SetState(ESectionState NewState) {
	switch (NewState) {
	case ESectionState::READY:
	{
		Trigger->SetCollisionProfileName(TEXT("ABTrigger"));
		for (UBoxComponent* GateTrigger : GateTriggers) {
			GateTrigger->SetCollisionProfileName(TEXT("NoCollision"));
		}

		OperateGates(true);
		break;
	}
	case ESectionState::BATTLE:
	{
		Trigger->SetCollisionProfileName(TEXT("NoCollision"));
		for (UBoxComponent* GateTrigger : GateTriggers) {
			GateTrigger->SetCollisionProfileName(TEXT("NoCollision"));
		}

		OperateGates(false);
		GetWorld()->GetTimerManager().SetTimer(SpawnNPCTimerHandle, FTimerDelegate::CreateUObject(this, &AABSection::OnNPCSpawn), EnemySpawnTime, false);
		
		GetWorld()->GetTimerManager().SetTimer(SpawnItemBoxTimerHandle, FTimerDelegate::CreateLambda([this]() -> void {
			FVector2D RandXY = FMath::RandPointInCircle(600.0f);
			GetWorld()->SpawnActor<AABItemBox>(GetActorLocation() + FVector(RandXY, 30.0f), FRotator::ZeroRotator);
			}), ItemBoxSpawnTime, false);

		break;
	}
	case ESectionState::COMPLETE: 
	{
		Trigger->SetCollisionProfileName(TEXT("NoCollision"));
		for (UBoxComponent* GateTrigger : GateTriggers) {
			GateTrigger->SetCollisionProfileName(TEXT("ABTrigger"));
		}

		OperateGates(true);
		break;
	}
	}	

	CurrentState = NewState;
}

void AABSection::OperateGates(bool bOpen) {
	for (UStaticMeshComponent* Gate : GateMeshes) {
		Gate->SetRelativeRotation(bOpen ? FRotator(0.0f, -90.0f, 0.0f) : FRotator::ZeroRotator);
	}
}

void AABSection::OnConstruction(const FTransform& Transform) {
	Super::OnConstruction(Transform);
	SetState(bNoBattle ? ESectionState::COMPLETE : ESectionState::READY);
}

void AABSection::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if (CurrentState == ESectionState::READY) {
		SetState(ESectionState::BATTLE);
	}
}

void AABSection::OnGateTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	ABCHECK(OverlappedComponent->ComponentTags.Num() == 1);
	FName ComponentTag = OverlappedComponent->ComponentTags[0];
	FName SocketName = FName(*ComponentTag.ToString().Left(2));
	ABLOG(Warning, TEXT("%s %s"), *ComponentTag.ToString(), *SocketName.ToString());
	if (!Mesh->DoesSocketExist(SocketName)) return;

	FVector NewLocation = Mesh->GetSocketLocation(SocketName);

	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams CollisionQueryParam(NAME_None, false, this);
	FCollisionObjectQueryParams ObjectQueryParam(FCollisionObjectQueryParams::InitType::AllObjects);
	bool bResult = GetWorld()->OverlapMultiByObjectType(
		OverlapResults,
		NewLocation,
		FQuat::Identity,
		ObjectQueryParam,
		FCollisionShape::MakeSphere(775.0f),
		CollisionQueryParam
	);

	if (!bResult) {
		auto NewSection = GetWorld()->SpawnActor<AABSection>(NewLocation, FRotator::ZeroRotator);
	}
	else {
		ABLOG(Warning, TEXT("New section area is not empty. "));
	}
}

void AABSection::OnNPCSpawn() {
	GetWorld()->SpawnActor<AABCharacter>(GetActorLocation() + FVector::UpVector * 88.0f, FRotator::ZeroRotator);
}

~~~

#### 학습내용 정리
