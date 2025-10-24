#include <Geode/Geode.hpp>

using namespace geode::prelude;
#include "Layers/CreditsLayer.h"
#include <Geode/modify/GManager.hpp>

namespace globals {

    inline std::string tr(const std::string& es, const std::string& en) {
        auto lang = Mod::get()->getSettingValue<std::string>("language");
        return (lang == "English" ? en : es);
    }
}

using namespace globals;

class $modify(MyGManager, GManager)
{
     void setup() {
        auto compare = std::string(m_fileName);

        compare.insert(std::string_view(compare).find(".dat"), "hardmode");

        m_fileName = compare;
        GManager::setup();
	}
};
