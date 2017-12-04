// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "NetWorking.h"
#include "TcpRecvThread.h"
#include "TcpSendThread.h"
#include "ShooterNetWorkConnect.h"

ShooterNetWorkConnect::ShooterNetWorkConnect() : ClientSocket(nullptr) , SendThread(nullptr) , RecvThread(nullptr)
{
    
}

ShooterNetWorkConnect::~ShooterNetWorkConnect()
{
    if (SendThread)
    {
        delete SendThread;
        SendThread = nullptr;
    }
    if (RecvThread)
    {
        delete RecvThread;
        RecvThread = nullptr;
    }
}

bool ShooterNetWorkConnect::Create(FString ServerIP, int ServerPort)
{
    ISocketSubsystem* SocketSubsystem = ISocketSubsystem::Get();
    
    FString HostIp = ServerIP;
    // convert the string to a ip addr structure
    // DEFAULT_TCP_FILE_SERVING_PORT is overridden
    TSharedRef<FInternetAddr> Addr = SocketSubsystem->CreateInternetAddr(0, ServerPort);
    bool bIsValid;
    
    Addr->SetIp(*HostIp, bIsValid);
    
    if (bIsValid)
    {
        // create the socket
        ClientSocket = SocketSubsystem->CreateSocket(NAME_Stream, TEXT("ShooterNetWorkConnect tcp"));
        
        // try to connect to the server
        if (ClientSocket == nullptr || ClientSocket->Connect(*Addr) == false)
        {
            // on failure, shut it all down
            SocketSubsystem->DestroySocket(ClientSocket);
            ClientSocket = NULL;
            UE_LOG(LogShooter, Error, TEXT("Failed to connect to file server at %s."), *Addr->ToString(true));
            return false;
        }
    }
    
    SendThread = FRunnableThread::Create( new FTcpSendThread(this) , TEXT("SendThread") );
    RecvThread = FRunnableThread::Create( new FTcpRecvThread(this) , TEXT("RecvThread") );
    
    
    return true;
}

bool ShooterNetWorkConnect::Send(const Message* msg)
{
    return true;
}

Message* ShooterNetWorkConnect::Pop()
{
    return nullptr;
}
