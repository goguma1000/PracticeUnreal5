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
