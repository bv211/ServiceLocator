#pragma once
#include "IService.h"
#include <map>

using namespace std;

namespace Services {
    class ServiceLocator {
        map<const type_info*, IService*> _services;
        static ServiceLocator* _instance;

        ServiceLocator() = default;

        public:
        static ServiceLocator* Instance(){
            if (_instance == nullptr)
                _instance = new ServiceLocator();

            return _instance;    
        }

        template <class T> 
        void Register(T* service) {
            auto type = &typeid(*service);    
            if (Contains(type)){
                cout << "Key already exist" << endl;
                return;
            }

            _services[type] = service;
        }

        template <class T>
        void Unregister() {
            auto service = GetService<T>();
            auto type = &typeid(*service);    
            _services.erase(type);
        }

        template <class T>
        T* GetService() {
            auto type = &typeid(T);

            if (!Contains(type))
                throw std::out_of_range("key not found");

            auto service = _services[type];
            return dynamic_cast<T *>(service);
        }

        private:
        bool Contains(const type_info* key){
            return _services[key] != nullptr;
        }
    };

    ServiceLocator* ServiceLocator::_instance = nullptr;
}