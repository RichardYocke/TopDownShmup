// Fill out your copyright notice in the Description page of Project Settings.


#include "DwarfCharacter.h"
#include "AIDwarfController.h"

ADwarfCharacter::ADwarfCharacter()
{
	AIControllerClass = AAIDwarfController::StaticClass();
}


void ADwarfCharacter::StartAttack()
{
	
	PlayAnimMontage(AttackAnim);
}

void ADwarfCharacter::StopAttack()
{
	StopAnimMontage();
}