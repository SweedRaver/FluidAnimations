// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "GridTerrain.h"
#include "GridPawn.generated.h"

UCLASS()
class ORTHOTESTFLEX_API AGridPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGridPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
	UFUNCTION(BlueprintCallable, Category="Initialization") void init();
	UFUNCTION(BlueprintCallable, Category="Initialization") void spawnCubes();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dimensions") int32 width = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dimensions") int32 height = 0;

private:
	bool mouseDown;
	float X = -1, Y = -1;
	GridTerrain* gt = NULL;
	TArray<int64, FDefaultAllocator>* DestroyedCubes = NULL;
	TSubclassOf<class ADestructibleCubeActor> MyItemBlueprint;
	const float SCALE_FACTOR = 100.0f;

	inline void OnClick();
	inline void OnRelease();
	inline FVector2D GetMouseWorldPosition();
	inline void DestroyTerrainLine(int x1, int y1, int x2, int y2, int l);
	inline void DestroyCube(int x, int y);
};
