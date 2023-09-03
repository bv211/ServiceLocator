#pragma once
#include <string>
#include "IService.h"

using namespace std;

namespace Services {
    class SaveLoadService : public IService {
        string _path{"file.txt"};

    public:
        SaveLoadService() = default;
        SaveLoadService(const string &path) : _path(path) {}

        void Save(){
        }

        void Load(){
        }
    };
}