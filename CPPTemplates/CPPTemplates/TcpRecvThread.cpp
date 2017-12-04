// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "ShooterNetWorkConnect.h"
#include "NetWorking.h"
#include "TcpRecvThread.h"

FTcpRecvThread::FTcpRecvThread(  ShooterNetWorkConnect* client ) : ClientConnect( client )
{
}

FTcpRecvThread::~FTcpRecvThread()
{
}


bool FTcpRecvThread::Init()
{
    TaskCounter.Increment();
    return FRunnable::Init();
}

uint32 FTcpRecvThread::Run()
{
    
    if (TaskCounter.GetValue() > 0)
    {
        // to send msg
    }
    
    return  1;
}

void FTcpRecvThread::Stop()
{
    TaskCounter.Decrement();
    FRunnable::Stop();
}

void FTcpRecvThread::Exit()
{
    FRunnable::Exit();
}
