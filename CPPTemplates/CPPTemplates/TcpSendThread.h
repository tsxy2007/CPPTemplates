// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class FSocket;
class ShooterNetWorkConnect;
class FThreadSafeCounter;
/**
 * 
 */
class SHOOTERGAME_API FTcpSendThread : public FRunnable
{
public:
	FTcpSendThread(ShooterNetWorkConnect* client);

    ~FTcpSendThread();

private:
    TSharedPtr<ShooterNetWorkConnect>        NetWorkConnect;
    
    FThreadSafeCounter                       TaskCounter;

public:
    virtual bool Init() override;
    
    virtual uint32 Run() override;
    
    virtual void Stop()override;
    
    virtual void Exit()override;

};
