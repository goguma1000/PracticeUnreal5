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
