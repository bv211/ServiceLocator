#include <iostream>
#include "Services/ServiceLocator.h"
#include "Services/IService.h"
#include "Services/NetworkService.h"
#include "Services/SaveLoadService.h"

using namespace Services;

namespace Infrastructure {
    class Bootstrap {
        public:
        Bootstrap() {
            auto services = Services::ServiceLocator::Instance();
            services->Register(new SaveLoadService());
            services->Register(new NetworkService());
            cout << "Сервисы загружены" << endl;
        }
    };
}