// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

struct Message;
class FRunnableThread;
/**
 * 
 */
class SHOOTERGAME_API ShooterNetWorkConnect : public TSharedFromThis<ShooterNetWorkConnect>
{
private:
    FSocket*                        ClientSocket;
    
    FRunnableThread*                SendThread;
    
    FRunnableThread*                RecvThread;
    
//    TQueue<Message>     SendQueue;
    
public:
	ShooterNetWorkConnect();
    
	~ShooterNetWorkConnect();
    
public:
    bool Create(FString ServerIP,int ServerPort);
    
    bool Send(const Message* msg);
    
    Message* Pop();
};
