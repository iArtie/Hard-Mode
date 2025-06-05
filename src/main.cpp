#include <Geode/Geode.hpp>

using namespace geode::prelude;
#include "Layers/CreditsLayer.h"
#include <Geode/modify/GManager.hpp>

//void removeUITint(CCLayer* layer, std::string name) {
//    auto spr = layer->getChildByID(name);
//    if (spr) static_cast<CCSprite*>(spr)->setColor(ccWHITE);
//}
class $modify(MyGManager, GManager)
{
     void setup() {
        auto compare = std::string(m_fileName);

        compare.insert(std::string_view(compare).find(".dat"), "hardmode");

        m_fileName = compare;
        GManager::setup();
	}
};
//
//
#include <Geode/modify/MenuLayer.hpp>
// swap coin textures
class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto GM = GameManager::sharedState();

        auto editorButton = typeinfo_cast<CCMenuItemSpriteExtra*>(this->getChildByID("main-menu")->getChildByID("editor-button"));

		this->getChildByID("right-side-menu")->getChildByID("daily-chest-button")->setVisible(false);

        if (this->getChildByID("character-select-hint"))
        {
            this->getChildByID("character-select-hint")->setVisible(false);
        }
        if (this->getChildByID("level-editor-hint"))
        {
            this->getChildByID("level-editor-hint")->setVisible(false);
        }
        //// test if already swapped textures
        //if (swappedTextures) return true;
        //else swappedTextures = true;
		auto grayButton = CCSpriteGrayscale::createWithSpriteFrameName("GJ_creatorBtn_001.png");
		
		editorButton->setSprite(grayButton);
      

        return true;
    }

    void onCreator(CCObject* sender)
    {
    
		/*MenuLayer::onCreator(sender);*/
        auto array = CCArray::create();
        
		auto firstTime = Mod::get()->getSavedValue<bool>("first-time");

	
        if (firstTime == false) {

            array->addObject(DialogObject::create("Darkness", "<d90> Despues de <cy>mucho tiempo</c>, parte de mi <cr>plan</c> esta en marcha.", 15, 1, false, { 255, 255, 255 }));

            array->addObject(DialogObject::create("Darkness", "<co>Infecte</c> el juego y <cr>bloquee</c> contacto con <cy>jugadores</c> y <cb>niveles</c>.", 15, 1, false, { 255, 255, 255 }));

            array->addObject(DialogObject::create("Darkness", "La <cr>seguridad</c> del juego <cy>aun me limita</c>. <d90> No puedo completar mi plan.", 15, 1, false, { 255, 255, 255 }));

            array->addObject(DialogObject::create("Darkness", "Si <cp>quieres detenerme</c>, enfrenta los <cr>niveles principales</c> que <cy>alguna vez RobTop llego a crear</c>.", 15, 1, false, { 255, 255, 255 }));

            array->addObject(DialogObject::create("Darkness", "Solo <cy>superando todos ellos</c> podrias tener una <cb>minima oportunidad</c>.", 15, 1, false, { 255, 255, 255 }));

            array->addObject(DialogObject::create("Darkness", "<cc>Aunque te <cr>advierto</c>...", 15, 1, false, { 255, 255, 255 }));

            array->addObject(DialogObject::create("Darkness", "Son mas <cr>dificiles</c> de lo que imaginas. <d90> Dudo que <cb>lo logres</c> antes de que acabe mi <cr>plan</c>.", 15, 1, false, { 255, 255, 255 }));

            array->addObject(DialogObject::create("Darkness", "Sin mas que decir...", 15, 1, false, { 255, 255, 255 }));

            array->addObject(DialogObject::create("Darkness", "<d60> <s250> <cy>Bienvenido</c> </s> <s250>al</s> <s250> <cr>HARD MODE</c>.</s>", 15, 1, false, { 255, 255, 255 }));
           
            Mod::get()->setSavedValue<bool>("first-time", true);
		}
		else {
			array->addObject(DialogObject::create("Darkness", "<d60> <s250> <cr>DEJA DE INSISTIR</c>.</s>", 15, 1, false, { 255, 255, 255 }));
			
		}
        auto dialog = DialogLayer::createDialogLayer(nullptr, array, 5);
        dialog->animateInRandomSide();
        CCScene::get()->addChild(dialog);
        
        /*  this->getParent()->setVisi*/
    }

	void onMoreGames(CCObject* sender)
	{
		/*auto creditsLayer = CommunityCreditsPage::create();*/

        auto creditsLayer = CreditsLayer::create();
		creditsLayer->show();

        //creditsLayer->m_pageObjects->removeAllObjects();
        ///* creditsLayer->removeChild(m_pageObjects);*/

        //creditsLayer->removeChild(creditsLayer->m_prevButton);

        //creditsLayer->removeChild(creditsLayer->m_nextButton);
	}
    void swapTexture(std::string goldKey, std::string userKey) {
        auto textureCache = CCSpriteFrameCache::get();
        auto goldTexture = textureCache->spriteFrameByName(goldKey.c_str());
        textureCache->removeSpriteFrameByName(userKey.c_str());
        textureCache->addSpriteFrame(goldTexture, userKey.c_str());
    }
};

#include <Geode/modify/GameObject.hpp>

//// pickup effect
//class $modify(GameObject) {
//
//    void updateCustomScaleX(float a1)
//    {
//       
//        if (this->m_objectID == 142) {
//        /*    this->m_particle->setStartColor({ 255,255,0 });
//
//            this->m_particle->setEndColor({ 255,255,0 });
//            auto color = ccColor3B{ 255,255,0 };*/
//
//		/*	if (this->m_particle) {
//                this->m_particle->setVisible(false);
//			}*/
//           
//            /*this->setVisible(false);*/
//            log::debug("{}","Si entro en la secret coin");
//        }
//        return GameObject::updateCustomScaleX(a1);
//        //else return GameObject::commonSetup();
//    }
//  //  cocos2d::CCParticleSystemQuad* createAndAddParticle(int p0, char const* plistName, int p2, cocos2d::tCCPositionType positionType)
//  //  {
//		//if (this->m_objectID == 142) {
//  //          this->m_particle->setStartColor({ 255,255,0 });
//
//  //          this->m_particle->setEndColor({ 255,255,0 });
//		//	auto color = ccColor3B{ 255,255,0 };
//		//	/*this->setVisible(false);*/
//  //          return GameObject::createAndAddParticle(p0,plistName, p2, positionType);
//		//}
//  //     
//		//else return GameObject::createAndAddParticle(p0, plistName, p2, positionType);
//  //  }
//  //
//};

#include <Geode/modify/PlayLayer.hpp>
class $modify(PlayLayer)
{
    void addObject(GameObject* a1)
    {
        if (a1->m_objectID == 142) {
            a1->m_hasNoParticles = false;
            a1->claimParticle();

            if (a1->m_particle != nullptr)
            {
                
                a1->m_particle->setStartColor(ccc4f(1.0f, 0.4f, 0.4f, 0.6f));   // Rojo claro + algo de transparencia
                a1->m_particle->setEndColor(ccc4f(0.5f, 0.0f, 0.0f, 1.0f));     // Rojo oscuro y opaco

                a1->m_particle->setBlendFunc({ GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA }); // Blending tradicional
            }
        }

        PlayLayer::addObject(a1);
     
    }

   /* virtual void currencyWillExit(CurrencyRewardLayer* a1)
    {

    }*/
  //  void levelComplete()
  //  {

  //     /* this->m_coinsCollected = 3;*/
  //      PlayLayer::levelComplete();

  //      //GameStatsManager::sharedState()->completedLevel(this->m_level);


	
  //      //if (!Mod::get()->getSettingValue<bool>("goldUI")) return;

  //      //removeUITint(m_mainLayer, "coin-1-sprite");
  //      //removeUITint(m_mainLayer, "coin-2-background");
  //      //removeUITint(m_mainLayer, "coin-3-sprite");
  //      //removeUITint(m_mainLayer, "coin-4-background");
  //      //removeUITint(m_mainLayer, "coin-5-sprite");
  //      //removeUITint(m_mainLayer, "coin-6-background");

  //      //// coin collect effect
  //      //for (CCSprite* spr : CCArrayExt<CCSprite*>(m_coinsToAnimate)) {
  //      //    spr->setColor(ccWHITE);
  //      //}
  //     
		//std::cout << "Coins collected: " << this->m_coinsCollected << std::endl;
  //     

  //      std::cout << "Coins collected for level (GameStatsManager): " << GameStatsManager::sharedState()->getCollectedCoinsForLevel(this->m_level) << std::endl;


  //      std::cout << "Coins array: " << this->m_coinArray << std::endl;

  //      
  //  }
	/*void update(float dt) {
		PlayLayer::update(dt);
		
	}*/
};

#include <Geode/modify/ProfilePage.hpp>
class $modify(ProfilePage) {
    static ProfilePage* create(int p0, bool p1) {
        auto ret = ProfilePage::create(p0, false);
        return ret;
    }

    void onSendMessage(CCObject*) {}
    void onFriend(CCObject*) {}
    void onBlockUser(CCObject*) {}
    void onCommentHistory(CCObject*) {}
    void onMyLevels(CCObject*) {}
    void onMyLists(CCObject*) {}
};


#include <Geode/modify/OptionsLayer.hpp>
class $modify(OptionsLayer) {
   
    void onAccount(CCObject*) {
    
        auto array = CCArray::create();


        array->addObject(DialogObject::create("RobTop", "<cp>Acaso crees</c> que vas a <co>tener tu cuenta</c> aqui? <d60> <s200> <cr>Bruh... </c> </s>", 28, 1, false, { 255, 255, 255 }));

    
        auto accDialog = DialogLayer::createDialogLayer(nullptr, array, 2);

		accDialog->animateInRandomSide();

        CCScene::get()->addChild(accDialog);

    }
};


#include <Geode/modify/CurrencyRewardLayer.hpp>
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
            // Partículas: CCParticleSystemQuad
            if (auto particle = dynamic_cast<CCParticleSystemQuad*>(obj)) {
                auto startColor = particle->getStartColor(); // ccColor4F
                if (startColor.r == 1.0f && startColor.g == 1.0f && startColor.b == 0.0f) {
                    particle->setStartColor(ccc4f(1.0f, 0.0f, 0.0f, startColor.a));
                    particle->setEndColor(ccc4f(1.0f, 0.0f, 0.0f, particle->getEndColor().a));
                }
                continue;
            }

        }
        //if (this->m_objects)
        //{
        //    CCObject* obj;
        //    CCARRAY_FOREACH(this->m_objects, obj) {
        //        // Verificamos si es un sistema de partículas
        //        if (auto particle = dynamic_cast<CCParticleSystemQuad*>(obj)) {
        //            particle->setStartColor(ccc4f(1.0f, 0.0f, 0.0f, 1.0f)); // Rojo puro
        //            particle->setEndColor(ccc4f(1.0f, 0.0f, 0.0f, 0.0f));   // Se desvanece
        //        }

        //        //// Verificamos si es un CCSpriteBatchNode
        //        //else if (auto batch = dynamic_cast<CCSpriteBatchNode*>(obj)) {
        //        //    batch->setColor(ccc3(255, 0, 0)); // Rojo puro
        //        //  
        //        //}
        //    }

        //}
    }

    void pulseSprite(cocos2d::CCSprite*)
    {

    }

 //   void pulseSprite(cocos2d::CCSprite* a1)
 //   {
 //       
	///*	if(this->m_starsLabel != nullptr)
	//   {
	//	this->m_starsLabel->setColor({ 255,48,48 });
	//    }
 //       CurrencyRewardLayer::pulseSprite(a1);*/
 //   }
};
#include <Geode/modify/EndLevelLayer.hpp>
class $modify(EndLevelLayer)
{
    //void currencyEnterFinished()
    //{
    //    
    //    //EndLevelLayer::starEnterFinished();

		
    //    //if (!Mod::get()->getSettingValue<bool>("goldUI")) return;

    //    //removeUITint(m_mainLayer, "coin-1-sprite");
    //    //removeUITint(m_mainLayer, "coin-2-background");
    //    //removeUITint(m_mainLayer, "coin-3-sprite");
    //    //removeUITint(m_mainLayer, "coin-4-background");
    //    //removeUITint(m_mainLayer, "coin-5-sprite");
    //    //removeUITint(m_mainLayer, "coin-6-background");

    //    //// coin collect effect
    //    //for (CCSprite* spr : CCArrayExt<CCSprite*>(m_coinsToAnimate)) {
    //    //    spr->setColor(ccWHITE);
    //    //}
    //}

    //void starEnterFinished()
    //{
    //   /* if (!this->m_playLayer) return;*/

    //    int stars = this->m_playLayer->m_level->m_stars; // o como sea que lo obtenés
    //    CCPoint pos = this->m_starsPosition + ccp(0, 8);

    //    auto particle = cocos2d::CCParticleSystemQuad::create("starEffect.plist",true);
    //    if (particle) {
    //        // Cambiar color de las partículas a rojo
    //        particle->setStartColor(ccc4f(1.0f, 0.0f, 0.0f, 1.0f));
    //        particle->setEndColor(ccc4f(1.0f, 0.0f, 0.0f, 0.0f)); // opcionalmente fade out

    //        particle->setPosition(pos);
    //        this->addChild(particle, 9);
    //    }

    //    auto wave = CCCircleWave::create(10.0f, 90.0, 0.4, 0.0f);
    //    wave->setPosition(pos);
    //    this->addChild(wave, 9);

    //    this->playEndEffect();
    //}

  //  void playStarEffect(float a1)
  //  {
		//EndLevelLayer::playStarEffect(a1);
	
  //  }
	/*void onMenu(cocos2d::CCObject* pSender) {

		this->m_playLayer->m_level->m_levelID = this->m_playLayer->m_level->m_levelID - 6500;
		EndLevelLayer::onMenu(pSender);


	}*/

    //void coinEnterFinished(CCPoint p) {
    //    if (!Mod::get()->getSettingValue<bool>("goldUI")) return;
    //    bool notLocal = m_notLocal;
    //    m_notLocal = false; // use 'official level' particles
    //    EndLevelLayer::coinEnterFinished(p);
    //    m_notLocal = notLocal;
    //}

    void playCurrencyEffect(float p0) {
    
        /*EndLevelLayer::playCurrencyEffect(p0);*/
    }

};

//#include <Geode/modify/PauseLayer.hpp>
//class $modify(PauseLayer) {
//    void onQuit(CCObject * sender) {
//
//        auto GM = GameManager::sharedState();
//       
//        GM->m_playLayer->m_level->m_levelID = GM->m_playLayer->m_level->m_levelID - 6500;
//        PauseLayer::onQuit(sender);
//    }
//};
//
#include <Geode/modify/GameManager.hpp>
class $modify(GameManager) {
    bool isIconUnlocked(int id, IconType type)
    {
        if (Mod::get()->getSettingValue<bool>("unlock-all") == true) {
            return true;
        }
        else
            return GameManager::isIconUnlocked(id, type);
        
    }

    bool isColorUnlocked(int id, UnlockType type)
    {
		if (Mod::get()->getSettingValue<bool>("unlock-all") == true) {
            return true;
		}
		else
			return GameManager::isColorUnlocked(id, type);
        
    }

    void dataLoaded(DS_Dictionary* dict) {
        GameManager::dataLoaded(dict);
    }
	
};

#include <Geode/modify/CurrencySprite.hpp>

class $modify(CurrencySprite)
{
    bool init(CurrencySpriteType type, bool burst) {
        // Llamada al init de la superclase o configuración inicial...
        if (!CurrencySprite::init(type,burst)) {
            return false;
        }

        // Guarda el tipo para referencia
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
#include <Geode/modify/LocalLevelManager.hpp>
class $modify(MyLocalLevelManager, LocalLevelManager)
{
	gd::string getMainLevelString(int id) {
        auto file = CCString::createWithFormat("hardmode-%i.txt"_spr, id);
        if (file == nullptr) return "";
        auto content = CCString::createWithContentsOfFile(file->getCString());
        if (content == nullptr) return "";
      
        return gd::string(content->getCString());
        return LocalLevelManager::getMainLevelString(id);
       
	}
};

#include <Geode/modify/LevelTools.hpp>
class $modify(HardModeLevelTools, LevelTools)
{
	static bool verifyLevelIntegrity(std::string verifyString, int levelID)
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

#include <Geode/modify/EditorUI.hpp>
class $modify(MyEditorUI, EditorUI)
{
    void setupCreateMenu()
    {
        EditorUI::setupCreateMenu();

        auto m_tab8 = static_cast<EditButtonBar*>(this->m_createButtonBars->objectAtIndex(8));
        m_tab8->m_buttonArray->insertObject(this->getCreateBtn(142, 4), 1);

        int rowCount = GameManager::get()->getIntGameVariable("0049");
        int columnCount = GameManager::get()->getIntGameVariable("0050");

        m_tab8->reloadItems(rowCount, columnCount);
    }
};

#include <Geode/modify/LevelPage.hpp>
class $modify(MyLevelPage, LevelPage)
{
    void updateDynamicPage(GJGameLevel* level) { 
      
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

#include <Geode/modify/EditorPauseLayer.hpp>
class $modify(MyEditorPauseLayer, EditorPauseLayer)
{
    bool init(LevelEditorLayer * editorLayer)
    {
        if (!EditorPauseLayer::init(editorLayer))
            return false;

        auto copySpr = ButtonSprite::create("Save\nString", 50, 30, 0.4f, true, "bigFont.fnt", "GJ_button_04.png");
        copySpr->setScale(0.8);

        auto copyBtn = CCMenuItemSpriteExtra::create(copySpr, this, menu_selector(MyEditorPauseLayer::copyStringToClipboard));
        copyBtn->setPositionX(70);

        auto menu = static_cast<CCMenu*>(this->getChildren()->objectAtIndex(1));
        menu->addChild(copyBtn);

        return true;
    }

    void copyStringToClipboard(CCObject*)
    {
        log::debug("{}", m_editorLayer->m_level->m_levelString);
        clipboard::write(m_editorLayer->m_level->m_levelString);
    }
};

#include <Geode/modify/LoadingLayer.hpp>
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
			auto bg = typeinfo_cast<CCSprite*>(this->getChildByID("bg-texture"));
            bg->setColor({197,0,0});
			});
        if (!GM->getUGV("30")) {
            GM->setUGV("30", true);
        }

      
     
        return true;
    }

    void loadAssets()
    {
		LoadingLayer::loadAssets();
//		
//
//       
//
//#ifdef GEODE_IS_WINDOWS
//
//
//     
//
//#endif
//#ifdef GEODE_IS_ANDROID
//
//
//        zipFilePath = geode::Mod::get()->getResourcesDir().string() + "/" + "hardmodeTextures.zip";
//
//        unzipDir = geode::Mod::get()->getResourcesDir().string() + "/" + "hardmodeTextures";
//
//#endif
//        

    }
};
//
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
	/*	auto towerLevel = GJGameLevel::create();
		towerLevel->m_levelID = -2;*/
		auto comingSoon = GJGameLevel::create();
		comingSoon->m_levelID = -1;

		/*m_scrollLayer->m_dynamicObjects->addObject(towerLevel);*/
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