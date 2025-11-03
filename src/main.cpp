#include <Geode/Geode.hpp>
#include <Geode/modify/GManager.hpp>

using namespace geode::prelude;


class $modify(MyGManager, GManager)
{
     void setup() {
        auto compare = std::string(m_fileName);

        compare.insert(std::string_view(compare).find(".dat"), "hardmode");

        m_fileName = compare;
        GManager::setup();
	}
};
