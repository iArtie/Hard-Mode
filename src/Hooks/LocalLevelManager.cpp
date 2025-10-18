#include <Geode/modify/LocalLevelManager.hpp>

using namespace geode::prelude;

class $modify(LocalLevelManager)
{
    gd::string getMainLevelString(int id) {
        auto file = CCString::createWithFormat("hardmode-%i.txt"_spr, id);
        if (file == nullptr) return "";
        auto content = CCString::createWithContentsOfFile(file->getCString());
        if (content == nullptr) return "";

        return gd::string(content->getCString());
        return LocalLevelManager::getMainLevelString(id);

    }
};
