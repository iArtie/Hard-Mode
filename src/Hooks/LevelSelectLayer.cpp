#include <Geode/modify/LevelSelectLayer.hpp>

using namespace geode::prelude;

class $modify(LevelSelectLayer) {

	bool init(int page) {

		if (!LevelSelectLayer::init(page)) return false;

		m_scrollLayer->m_dynamicObjects->removeAllObjects();

		auto dotsArray = CCArrayExt<CCSprite*>(m_scrollLayer->m_dots);

		for (CCSprite* dot : dotsArray) {
			dot->removeFromParent();
		}

		m_scrollLayer->m_dots->removeAllObjects();

		for (int i = 1; i < 14; i++) {
			m_scrollLayer->m_dynamicObjects->addObject(GameLevelManager::get()->getMainLevel(i, true));
		}

		auto comingSoon = GJGameLevel::create();
		comingSoon->m_levelID = -1;


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