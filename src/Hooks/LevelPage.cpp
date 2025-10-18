#include <Geode/modify/LevelPage.hpp>
#include "../main.cpp"


using namespace geode::prelude;

class $modify(LevelPage)
{
    void onInfo(cocos2d::CCObject * sender)
    {
        if (this->m_level->m_levelID == -1)
        {
            auto secret = FLAlertLayer::create(
                nullptr,
                "???",
                tr(
                    "<cj>El maravilloso mundo que solias conocer</c>\n<cr>esta desapareciendo..</c>\n<cg>Bienvenido</c> al <cy>HARD MODE</c>",
                    "<cj>The wonderful world you once knew</c>\n<cr>is fading away..</c>\n<cg>Welcome</c> to <cy>HARD MODE</c>"
                ).c_str(),
                tr("OK", "OK").c_str(),
                nullptr,
                360
            );
            secret->show();
        }
        else
        {
            LevelPage::onInfo(sender);
        }
    }

    void updateDynamicPage(GJGameLevel * level) {

        LevelPage::updateDynamicPage(level);

        if (level->m_demon == 1)
        {

            auto oldSprite = this->m_levelDisplay->getChildByTag(1337);
            if (oldSprite) oldSprite->removeFromParent();

            int demonValue = 0;

            switch (level->m_difficulty)
            {
            case GJDifficulty::DemonEasy:
                demonValue = 7;
                break;
            case GJDifficulty::DemonMedium:
                demonValue = 8;
                break;
            case GJDifficulty::DemonInsane:
                demonValue = 9;
                break;
            case GJDifficulty::DemonExtreme:
                demonValue = 10;
                break;
            }

            auto fileName = CCString::createWithFormat("diffIcon_0%d_btn_001.png", demonValue)->getCString();
            auto newDemonSprite = CCSprite::createWithSpriteFrameName(fileName);
            newDemonSprite->setPosition(this->m_difficultySprite->getPosition());
            newDemonSprite->setScale(this->m_difficultySprite->getScale());
            newDemonSprite->setTag(1337);

            this->m_levelDisplay->addChild(newDemonSprite);

            this->m_difficultySprite->setVisible(false);
        }
        else {

            auto oldSprite = this->m_levelDisplay->getChildByTag(1337);
            if (oldSprite) oldSprite->removeFromParent();

            this->m_difficultySprite->setVisible(true);
        }


    }
};