#include <Geode/modify/LoadingLayer.hpp>

using namespace geode::prelude;

class $modify(LoadingLayer)
{
    bool init(bool a1) {

        std::string zipFilePath;


        std::string unzipDir;

        zipFilePath = geode::Mod::get()->getResourcesDir().string() + "\\" + "hardmodeTextures.zip";

        unzipDir = geode::Mod::get()->getResourcesDir().string() + "\\" + "hardmodeTextures";

#ifdef GEODE_IS_ANDROID


        zipFilePath = geode::Mod::get()->getResourcesDir().string() + "/" + "hardmodeTextures.zip";

        unzipDir = geode::Mod::get()->getResourcesDir().string() + "/" + "hardmodeTextures";

#endif
        auto result = geode::utils::file::Unzip::intoDir(zipFilePath, unzipDir);

        CCFileUtils::get()->addTexturePack(CCTexturePack{
          .m_id = this->getID(),
          .m_paths = { unzipDir }
            });

        if (!LoadingLayer::init(a1))
            return false;

        auto GM = GameManager::sharedState();

        queueInMainThread([=]() {
            auto logo = typeinfo_cast<CCSprite*>(this->getChildByID("gd-logo"));
			logo->setPositionY(logo->getPositionY() + 30);
            auto bg = typeinfo_cast<CCSprite*>(this->getChildByID("bg-texture"));

            bg->setColor({ 197,0,0 });
            });
        if (!GM->getUGV("30")) {
            GM->setUGV("30", true);
        }

        return true;
    }

    void loadAssets()
    {
        LoadingLayer::loadAssets();


    }
};