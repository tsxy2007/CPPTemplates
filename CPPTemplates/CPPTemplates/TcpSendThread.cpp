// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "NetWorking.h"
#include "ShooterNetWorkConnect.h"
#include "TcpSendThread.h"

FTcpSendThread::FTcpSendThread(ShooterNetWorkConnect* client) : NetWorkConnect(client)
{
    
}

FTcpSendThread::~FTcpSendThread()
{
    
}

bool FTcpSendThread::Init()
{
    TaskCounter.Increment();
    return FRunnable::Init();
}

uint32 FTcpSendThread::Run()
{
    
    if (TaskCounter.GetValue() > 0)
    {
        // to send msg
    }
    
    return  1;
}

void FTcpSendThread::Stop()
{
    TaskCounter.Decrement();
    FRunnable::Stop();
}

void FTcpSendThread::Exit()
{
    FRunnable::Exit();
}
