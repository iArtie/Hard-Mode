#include <Geode/modify/LocalLevelManager.hpp>

using namespace geode::prelude;

class $modify(LocalLevelManager)
{
    gd::string getMainLevelString(int id) {
        auto file = fmt::format("hardmode-{}.txt"_spr, id);
        auto content = CCString::createWithContentsOfFile(file.c_str());
        if (content == nullptr)
            return LocalLevelManager::getMainLevelString(id);

        return gd::string(content->getCString());

    }
};
