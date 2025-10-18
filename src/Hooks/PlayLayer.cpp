#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(PlayLayer)
{
    void addObject(GameObject * a1)
    {
        if (a1->m_objectID == 142) {
            a1->m_hasNoParticles = false;
            a1->claimParticle();

            if (a1->m_particle != nullptr)
            {

                a1->m_particle->setStartColor(ccc4f(1.0f, 0.4f, 0.4f, 0.6f));  
                a1->m_particle->setEndColor(ccc4f(0.5f, 0.0f, 0.0f, 1.0f));    

                a1->m_particle->setBlendFunc({ GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA }); // Blending 
            }
        }

        PlayLayer::addObject(a1);

    }

};