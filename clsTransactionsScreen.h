#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalanceScreen.h"
#include "clsUser.h"
#include "clsTransferScreen.h"
#include "clsTransferHistoryScreen.h"

class clsTransactionsScreen : protected clsScreen
{
private:
    enum eTransaction
    {
        eDeposit = 1,
        eWithdraw = 2,
        eTotalBalances = 3,
        eTransfer = 4,
        eTransferHistory = 5,
        eMainMenu = 6
    };

    static short _ReadTransactionOption()
    {
        cout << setw(37) << left << "" << "Choose What You Want To Do? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number Between 1 And 6? ");

        return Choice;
    }

    static void _ShowDepositScreen()
    {
        //cout << "\nDeposit Screen Will Be Here...\n";
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        //cout << "\nWithdraw Screen Will Be Here...\n";
        clsWithdrawScreen::ShowWithdrawScreen();
    }
    
    static void _ShowTotalBalanceScreen()
    {
        //cout << "\nTotal Balance Screen Will Be Here...\n";
        clsTotalBalanceScreen::ShowTotalBalances();
    }

    static void _ShowTransferScreen()
    {
        //cout << "---------";
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferHistoryScreen()
    {
        //cout << "---------------";
        clsTransferHistoryScreen::ShowTransferHistoryScreen();
    }

    static void _GoBackToTransactionMenu()
    {
        cout << setw(37) << left << "\n\tPress Any Key To Go Back To Transaction Menu...";
        system("pause>0");
        ShowTransactionMenu();
    }

    static void _PerformTransactionMenuOption(eTransaction Choice)
    {
        switch (Choice)
        {
        case eTransaction::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionMenu();
            break;
        }

        case eTransaction::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionMenu();
            break;
        }

        case eTransaction::eTotalBalances:
        {
            system("cls");
            _ShowTotalBalanceScreen();
            _GoBackToTransactionMenu();
            break;
        }

        case eTransaction::eTransfer:
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionMenu();
            break;
        }

        case eTransaction::eTransferHistory:
        {
            system("cls");
            _ShowTransferHistoryScreen();
            _GoBackToTransactionMenu();
            break;
        }

        case eTransaction::eMainMenu:
        {
            //clsMainScreen::ShowMainMenu();
        }

        }
    }


public:

    static void ShowTransactionMenu()
    {

        if (!CheckAccessRights(clsUser::ePermissions::pTranactions))
        {
            return;		// It Will Exit The Function.
        }

        system("cls");
        _DrawHeaderScreen("\t    Transaction Menu");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer History.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";

        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionMenuOption(eTransaction(_ReadTransactionOption()));

    }

};

