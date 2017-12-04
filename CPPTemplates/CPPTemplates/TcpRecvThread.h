// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class ShooterNetWorkConnect;
class FThreadSafeCounter;
/**
 * 
 */
class SHOOTERGAME_API FTcpRecvThread : public FRunnable
{
private:
    TSharedPtr<ShooterNetWorkConnect>       ClientConnect;
    
    FThreadSafeCounter                      TaskCounter;
    
public:
	FTcpRecvThread( ShooterNetWorkConnect* client );
    
	~FTcpRecvThread();
    
public:
    virtual bool    Init() override;
    
    virtual uint32  Run() override;
    
    virtual void    Stop()override;
    
    virtual void    Exit()override;
};
