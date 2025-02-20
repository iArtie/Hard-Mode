#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/GManager.hpp>
class $modify(MyGManager, GManager)
{
     void setup() {
        auto compare = std::string(m_fileName);

        compare.insert(std::string_view(compare).find(".dat"), "HardMode");

        m_fileName = compare;
        GManager::setup();
	}
};

#include <Geode/modify/GameManager.hpp>
class $modify(GameManager) {
    bool isIconUnlocked(int id, IconType type)
    {
        if (type == IconType::Item)
            return GameManager::isIconUnlocked(id, type);

        return true;
    }

    bool isColorUnlocked(int id, UnlockType type)
    {
        return true;
    }


	//void dataLoaded(DS_Dictionary* dict)
	//{
	//	GameManager::dataLoaded(dict);
	//}
};


#include <Geode/modify/LocalLevelManager.hpp>
class $modify(MyLocalLevelManager, LocalLevelManager)
{
	gd::string getMainLevelString(int id) {
		if (id > 21)
			return LocalLevelManager::getMainLevelString(id); // Retorna el valor original

		auto file = CCString::createWithFormat("hardmode-%i.txt"_spr, id);
		if (file == nullptr) return "";

		auto content = CCString::createWithContentsOfFile(file->getCString());
		if (content == nullptr) return "";

		return gd::string(content->getCString());
	}
};

#include <Geode/modify/LevelTools.hpp>
class $modify(HardModeLevelTools, LevelTools)
{
	static bool verifyLevelIntegrity(std::string verifyString, int levelID)
	{
		return true;
	}
	static GJGameLevel* getLevel(int levelID, bool getString)
	{

		GJGameLevel* level = GJGameLevel::create();

        switch (levelID) {
        case 1:
            level->m_levelName = getAudioTitle(0);
            level->m_audioTrack = 0;
            level->m_stars = 3;
            level->m_difficulty = GJDifficulty::Normal;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 3;
            break;
        case 2:
            level->m_levelName = getAudioTitle(1);
            level->m_audioTrack = 1;
            level->m_stars = 4;
            level->m_difficulty = GJDifficulty::Normal;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 3;
            break;
        case 3:
            level->m_levelName = getAudioTitle(2);
            level->m_audioTrack = 2;
            level->m_stars = 5;
            level->m_difficulty = GJDifficulty::Hard;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 3;
            break;
        case 4:
            level->m_levelName = getAudioTitle(3);
            level->m_audioTrack = 3;
            level->m_stars = 6;
            level->m_difficulty = GJDifficulty::Hard;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 3;
            break;
        case 5:
            level->m_levelName = getAudioTitle(4);
            level->m_audioTrack = 4;
            level->m_stars = 7;
            level->m_difficulty = GJDifficulty::Harder;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 3;
            break;
        case 6:
            level->m_levelName = getAudioTitle(5);
            level->m_audioTrack = 5;
            level->m_stars = 8;
            level->m_difficulty = GJDifficulty::Harder;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 3;
            break;
        case 7:
            level->m_levelName = getAudioTitle(6);
            level->m_audioTrack = 6;
            level->m_stars = 9;
            level->m_difficulty = GJDifficulty::Insane;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 3;
            break;
        case 8:
            level->m_levelName = getAudioTitle(7);
            level->m_audioTrack = 7;
            level->m_stars = 10;
            level->m_difficulty = GJDifficulty::DemonEasy;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 3;
            break;
        case 9:
            level->m_levelName = getAudioTitle(8);
            level->m_audioTrack = 8;
            level->m_stars = 11;
            level->m_difficulty = GJDifficulty::Insane;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 3;
            break;
        case 10:
            level->m_levelName = getAudioTitle(9);
            level->m_audioTrack = 9;
            level->m_stars = 12;
            level->m_difficulty = GJDifficulty::DemonMedium;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 3;
            break;
        case 11:
            level->m_levelName = getAudioTitle(10);
            level->m_audioTrack = 10;
            level->m_stars = 13;
            level->m_difficulty = GJDifficulty::DemonMedium;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 3;
            break;
        case 12:
            level->m_levelName = getAudioTitle(11);
            level->m_audioTrack = 11;
            level->m_stars = 14;
            level->m_difficulty = GJDifficulty::DemonEasy;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 3;
            break;
        case 13:
            level->m_levelName = getAudioTitle(12);
            level->m_audioTrack = 12;
            level->m_stars = 13;
            level->m_difficulty = GJDifficulty::DemonEasy;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 3;
            break;
        default:
            return LevelTools::getLevel(levelID, getString);
        }



		if (!getString) {
			level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(levelID);
		}
		level->m_levelID = levelID;
		level->m_levelType = GJLevelType::Local;

		return level;


	}
};

#include <Geode/modify/LoadingLayer.hpp>
class $modify(LoadingLayer)
{
	void loadAssets()
	{
		LoadingLayer::loadAssets();
		auto GM = GameManager::sharedState();

		if (!GM->getUGV("30"))
			GM->setUGV("30", true);

		auto GSM = GameStatsManager::sharedState();

		auto GLM = GameLevelManager::sharedState();

		GSM->checkCoinAchievement(GLM->getMainLevel(1, false));
		GSM->checkCoinAchievement(GLM->getMainLevel(2, false));
		GSM->checkCoinAchievement(GLM->getMainLevel(3, false));
		GSM->checkCoinAchievement(GLM->getMainLevel(4, false));
		GSM->checkCoinAchievement(GLM->getMainLevel(5, false));
		GSM->checkCoinAchievement(GLM->getMainLevel(6, false));
		GSM->checkCoinAchievement(GLM->getMainLevel(7, false));
		GSM->checkCoinAchievement(GLM->getMainLevel(8, false));
		GSM->checkCoinAchievement(GLM->getMainLevel(9, false));
		GSM->checkCoinAchievement(GLM->getMainLevel(10, false));
	}

};

#include <Geode/modify/LevelSelectLayer.hpp>
class $modify(LevelSelectLayer) {

    bool init(int page) {

        if (!LevelSelectLayer::init(page)) return false;
		//Optimization code idea taked from gd lunar (big thanks to Capeling!)
		m_scrollLayer->m_dynamicObjects->removeAllObjects();

		auto dotsArray = CCArrayExt<CCSprite*>(m_scrollLayer->m_dots);

		for (CCSprite* dot : dotsArray) {
			dot->removeFromParent();
		}

		m_scrollLayer->m_dots->removeAllObjects();

		for (int i = 1; i < 14; i++) {
			m_scrollLayer->m_dynamicObjects->addObject(GameLevelManager::get()->getMainLevel(i, true));
		}
		auto towerLevel = GJGameLevel::create();
		towerLevel->m_levelID = -2;
		auto comingSoon = GJGameLevel::create();
		comingSoon->m_levelID = -1;

		m_scrollLayer->m_dynamicObjects->addObject(towerLevel);
		m_scrollLayer->m_dynamicObjects->addObject(comingSoon);

		auto batchNode = CCSpriteBatchNode::create("smallDot.png", 29);
		m_scrollLayer->addChild(batchNode, 5);

		for (int i = 0; i < m_scrollLayer->m_dynamicObjects->count(); i++) {
			auto sprite = CCSprite::create("smallDot.png");
			batchNode->addChild(sprite);
			m_scrollLayer->m_dots->addObject(sprite);
		}

		m_scrollLayer->updateDots(0.f);
		m_scrollLayer->updatePages();
		this->updatePageWithObject(m_scrollLayer->m_pages->objectAtIndex(page % 3), m_scrollLayer->m_dynamicObjects->objectAtIndex(page));
		this->m_scrollLayer->repositionPagesLooped();

        return true;
    }

  
};