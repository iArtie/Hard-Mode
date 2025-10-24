#include <Geode/modify/LevelTools.hpp>

using namespace geode::prelude;

class $modify(LevelTools)
{
    static bool verifyLevelIntegrity(gd::string verifyString, int levelID)
    {
        return true;
    }

    static GJGameLevel* getLevel(int levelID, bool loaded) {

        auto level = LevelTools::getLevel(levelID, loaded);

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
            level->m_demon = 1;
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
            level->m_demon = 1;
            level->m_difficulty = GJDifficulty::DemonMedium;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 3;
            break;
        case 11:
            level->m_levelName = getAudioTitle(10);
            level->m_audioTrack = 10;
            level->m_stars = 13;
            level->m_demon = 1;
            level->m_difficulty = GJDifficulty::DemonMedium;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 3;
            break;
        case 12:
            level->m_levelName = getAudioTitle(11);
            level->m_audioTrack = 11;
            level->m_stars = 14;
            level->m_demon = 1;
            level->m_difficulty = GJDifficulty::DemonEasy;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 3;
            break;
        case 13:
            level->m_levelName = getAudioTitle(12);
            level->m_audioTrack = 12;
            level->m_stars = 13;
            level->m_demon = 1;
            level->m_difficulty = GJDifficulty::DemonEasy;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 3;
            break;
        default:
            return level;
        }



        if (!loaded) {
            level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(levelID);
        }
        level->m_levelID = levelID;
        level->m_levelType = GJLevelType::Local;

        return level;


    }
};
