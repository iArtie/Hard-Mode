#include <Geode/modify/CurrencySprite.hpp>

using namespace geode::prelude;

class $modify(CurrencySprite)
{
    bool init(CurrencySpriteType type, bool burst) {

        if (!CurrencySprite::init(type, burst)) {
            return false;
        }

        m_spriteType = type;

        if ((int)type == 2)
        {
            this->initWithFile("GJ_bigStar_noShadow_001.png");
            m_burstSprite = CCSprite::createWithSpriteFrameName("shineBurst_001.png");
            m_burstSprite->retain();

            m_burstSprite->setColor({ 255,0,0 });

        }
        return true;
    }

};