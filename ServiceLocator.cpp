#include <iostream>
#include "Services/ServiceLocator.h"
#include "Services/IService.h"
#include "Bootstrap.h"

using namespace std;

int main(){
    auto boot = new Infrastructure::Bootstrap();
    
    auto services = Services::ServiceLocator::Instance();
    auto network = services->GetService<NetworkService>();

    network->SendMessage("192.168.1.1", "Hello");

    return 0;
}