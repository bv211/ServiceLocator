#pragma once
#include <iostream>
#include "IService.h"

using namespace std;

namespace Services {
    enum class IsAvailable {
        NotAvailable,
        Available
    };

    class NetworkService : public IService {
    public:
        NetworkService() = default;

        void SendMessage(const string &ip, const string &msg) {
            cout << ip << ':' << msg << endl;
        }

        IsAvailable GetStatus(const string &ip) {
            // code
            return IsAvailable::NotAvailable;
        }
    };
}