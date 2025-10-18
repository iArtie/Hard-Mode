#include <Geode/modify/CurrencyRewardLayer.hpp>

using namespace geode::prelude;

class $modify(CurrencyRewardLayer)
{
    virtual void update(float a1)
    {
        CurrencyRewardLayer::update(a1);

        if (this->m_starsLabel != nullptr)
        {
            this->m_starsLabel->stopAllActions();

            this->m_starsLabel->setColor({ 255,48,48 });
        }


        CCObject* obj;
        CCARRAY_FOREACH(this->getChildren(), obj) {
            if (auto particle = typeinfo_cast<CCParticleSystemQuad*>(obj)) {
                auto startColor = particle->getStartColor(); // ccColor4F
                if (startColor.r == 1.0f && startColor.g == 1.0f && startColor.b == 0.0f) {
                    particle->setStartColor(ccc4f(1.0f, 0.0f, 0.0f, startColor.a));
                    particle->setEndColor(ccc4f(1.0f, 0.0f, 0.0f, particle->getEndColor().a));
                }
                continue;
            }

        }
    }

    void pulseSprite(cocos2d::CCSprite*)
    {
		//Remove yellow pulse
    }
};