
#include "CreditsLayer.h"
#include "../main.cpp"
using namespace geode::prelude;

    bool CreditsLayer::setup() {
  
        this->setTitle(tr("Gracias por jugar!", "Thanks for playing!").c_str());
    
        float offset = 0.0f;
        std::vector<std::tuple<std::string, CCPoint, CCPoint, bool, bool>> corners = {
          {"bottomLeft",{0,0},{0,0},false,false},
          {"bottomRight",{this->m_mainLayer->getContentWidth(),0},{1,0},true,false },
          {"topLeft",{0,this->m_mainLayer->getContentHeight()},{0,1},false,true},
          {"topRight",{this->m_mainLayer->getContentWidth(),this->m_mainLayer->getContentHeight()},{1,1},true,true},
        };

        for (const auto& [name, pos, anchor, flipX, flipY] : corners) {
            auto corner = CCSprite::createWithSpriteFrameName("dailyLevelCorner_001.png");
            corner->setAnchorPoint(anchor);
            corner->setPosition(pos + CCPoint{ -offset * (1 - anchor.x * 2), -offset * (1 - anchor.y * 2) });
            corner->setFlipX(flipX);
            corner->setFlipY(flipY);
            corner->setID((name + "_spr").c_str());
            this->m_mainLayer->addChild(corner);
        }
        
       
     
		
		auto director = CCDirector::sharedDirector();
		auto usersLayer = CCLayer::create();

        //Organized
		auto layer1 = CCLayer::create();

        createProfilePlaceholder(layer1, "GersonGaming", 12, 41, 41, 107, 12018835, { 280,40 });
		
        auto customTitleLayer1 = CCLabelBMFont::create(
            tr("Organizado por", "Organized by").c_str(),
            "bigFont.fnt"
        );
		customTitleLayer1->setScale(0.8f);
		customTitleLayer1->setPosition({120,40});

		layer1->addChild(customTitleLayer1);
        

        //Levels creation
        auto layer2 = CCLayer::create();
   

        createProfilePlaceholder(layer2, "LennyCreator", 18, 3, 16, 62, 2114616,{63,40 });
        createProfilePlaceholder(layer2, "GersonGaming", 12, 41, 41, 107, 12018835, { 161,40 });

        auto customTitleLayer2 = CCLabelBMFont::create(
            tr("Creacion de\nniveles", "Level\nCreation").c_str(),
            "bigFont.fnt"
        );

        customTitleLayer2->setScale(0.6f);
        customTitleLayer2->setPosition({ 270,40 });

        layer2->addChild(customTitleLayer2);



        //Mod developer
		auto layer3 = CCLayer::create();
        layer3->setAnchorPoint({ 300, 200 });

        createProfilePlaceholder(layer3, "BitZGD", 12, 3, 1, 98, 7624979, { 291,40 });

        auto customTitleLayer3 = CCLabelBMFont::create("Mod Developer", "bigFont.fnt");
        customTitleLayer3->setScale(0.8f);
        customTitleLayer3->setPosition({ 120,40 });

        layer3->addChild(customTitleLayer3);



        //Artistic
		auto layer4 = CCLayer::create();
     
        
        auto customTitleLayer4 = CCLabelBMFont::create(
            tr("Apartado Artistico", "Artistic Section").c_str(),
            "bigFont.fnt"
        );
        customTitleLayer4->setScale(0.65f);
        customTitleLayer4->setPosition({ 215,40 });

        createProfilePlaceholder(layer4, "GhostPower13", 15, 1, 0, 121, 2678947, { 63,40 });


        layer4->addChild(customTitleLayer4);
     



		//Music
        auto layer5 = CCLayer::create();
 

        auto customTitleLayer5 = CCLabelBMFont::create(
            tr("Apartado Musical", "Music Section").c_str(),
            "bigFont.fnt"
        );
        customTitleLayer5->setScale(0.7f);
        customTitleLayer5->setPosition({ 120,40 });

        layer5->addChild(customTitleLayer5);

        createProfilePlaceholder(layer5, "SheccidM", 12, 3, 8, 122, 14384790, {291,40 });


        //Playtesters
        auto layer6 = CCLayer::create();
    

        auto customTitleLayer6 = CCLabelBMFont::create("Playtesters", "bigFont.fnt");
        customTitleLayer6->setScale(0.55f);
        customTitleLayer6->setPosition({ 170,73 });
  
        layer6->addChild(customTitleLayer6,-1);

        createProfilePlaceholder(layer6, "krystalite", 40, 12, 12, 99, 6575080, {301,25 });
        createProfilePlaceholder(layer6, "LennyCreator", 18, 3, 16, 62, 2114616, {211,25 });
        createProfilePlaceholder(layer6, "Rodaxis", 6, 3, -1, 35, 16469733, {131,25 });
        createProfilePlaceholder(layer6, "GerpowerGD", 1, 3, -1, 74, 10857191, {56,25 });

     
        auto layer7 = CCLayer::create();
      

        createProfilePlaceholder(layer7, "Morphirot", 4, 12, 3, 269, 245014, {231,40 });
        createProfilePlaceholder(layer7, "KiiwiStrawberry", 3, 2, -1, 329, 5952184, {111,40 });

		auto layersArray = CCArray::create();

		layersArray->addObject(layer1);
        layersArray->addObject(layer2);
        layersArray->addObject(layer3);
        layersArray->addObject(layer4);
        layersArray->addObject(layer5);
        layersArray->addObject(layer6);
        layersArray->addObject(layer7);

		m_mainLayer->addChild(usersLayer);
        usersLayer->setPosition(m_mainLayer->convertToNodeSpace(ccp(0, 0)));

		auto winSize = director->getWinSize();

  

    
        auto listView = ListView::create(layersArray,85, m_mainLayer->getContentSize().width - 95, 170.f);
     

        listView->ignoreAnchorPointForPosition(true);
		
        auto commentList = GJCommentListLayer::create(listView, "halo", { 191, 114, 62,255 }, 339, 170, false);

        
        commentList->setPosition(winSize / 2 - commentList->getScaledContentSize() / 2);

        usersLayer->addChild(commentList);
   
        m_mainLayer->setScale(0.2f);

        auto scaleUp = cocos2d::CCEaseExponentialOut::create(
            cocos2d::CCScaleTo::create(0.3f, 1.0f)
        );

        m_mainLayer->runAction(scaleUp);
    

        return true;
    }


    void CreditsLayer::createProfilePlaceholder(CCLayer* layer,const char* username, int color1, int color2, int colorGlow,int iconID, int accountID, CCPoint position)
    {
        auto gm = GameManager::sharedState();
        auto icon = SimplePlayer::create(iconID);

        auto userName = CCLabelBMFont::create(username, "goldFont.fnt");
        userName->setScale(0.52f);

		auto menu = CCMenu::create();

		auto usernameButton = CCMenuItemSpriteExtra::create(userName, this, menu_selector(CreditsLayer::toProfile));
		usernameButton->setTag(accountID);
		
       
        menu->setPosition({position.x, 55 });

       
		menu->addChild(usernameButton);
        layer->addChild(menu);

		
        icon->setColor(gm->colorForIdx(color1));
        icon->setSecondColor(gm->colorForIdx(color2));
        icon->setVisible(true);
        if (colorGlow > -1)
        {
            icon->setGlowOutline(gm->colorForIdx(colorGlow));
			icon->enableCustomGlowColor(gm->colorForIdx(colorGlow));
        }
        
        icon->setPosition({ position.x,position.y });
        if (position.y >= 40)
        {
            menu->setPosition({ position.x, 65 });
            icon->setPosition({ position.x,position.y-5 });
        }
	
        layer->addChild(icon);
    }

    void CreditsLayer::toProfile(CCObject* sender)
    {
		ProfilePage::create(sender->getTag(), false)->show();
    }
     CreditsLayer* CreditsLayer::create() {
        auto ret = new CreditsLayer();

		ret->m_noElasticity = true;
		auto director = CCDirector::sharedDirector();
        if (ret->initAnchored(434, 260, "GJ_square01.png")) {
            ret->autorelease();
            return ret;
        }

        delete ret;
        return nullptr;
    }

