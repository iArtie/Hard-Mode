#include <Geode/modify/MenuLayer.hpp>
#include "../main.cpp"

using namespace geode::prelude;

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

        auto grayButton = CCSpriteGrayscale::createWithSpriteFrameName("GJ_creatorBtn_001.png");

        editorButton->setSprite(grayButton);


        return true;
    }

    void onCreator(CCObject * sender)
    {
        auto array = CCArray::create();

        auto firstTime = Mod::get()->getSavedValue<bool>("first-time");


        if (firstTime == false) {

            array->addObject(DialogObject::create("Darkness", tr("<d90> Despues de <cy>mucho tiempo</c>, parte de mi <cr>plan</c> esta en marcha.", "<d90> After <cy>a long time</c>, part of my <cr>plan</c> is now in motion.").c_str(), 15, 1, false, { 255, 255, 255 }));
            array->addObject(DialogObject::create("Darkness", tr("<co>Infecte</c> el juego y <cr>bloquee</c> contacto con <cy>jugadores</c> y <cb>niveles</c>.", "I have <co>infected</c> the game and <cr>blocked</c> contact with <cy>players</c> and <cb>levels</c>.").c_str(), 15, 1, false, { 255, 255, 255 }));
            array->addObject(DialogObject::create("Darkness", tr("La <cr>seguridad</c> del juego <cy>aún me limita</c>. <d90> No puedo completar mi plan.", "The game's <cr>security</c> still <cy>limits me</c>. <d90> I can't finish my plan yet.").c_str(), 15, 1, false, { 255, 255, 255 }));
            array->addObject(DialogObject::create("Darkness", tr("Si <cp>quieres detenerme</c>, enfrenta los <cr>niveles principales</c> que <cy>alguna vez RobTop llegó a crear</c>.", "If you <cp>wish to stop me</c>, face the <cr>main levels</c> that <cy>RobTop once created</c>.").c_str(), 15, 1, false, { 255, 255, 255 }));
            array->addObject(DialogObject::create("Darkness", tr("Solo <cy>superando todos ellos</c> podrías tener una <cb>mínima oportunidad</c>.", "Only by <cy>beating all of them</c> will you have a <cb>tiny chance</c>.").c_str(), 15, 1, false, { 255, 255, 255 }));
            array->addObject(DialogObject::create("Darkness", tr("<cc>Aunque te <cr>advierto</c>...", "<cc>But I <cr>warn you</c>...").c_str(), 15, 1, false, { 255, 255, 255 }));
            array->addObject(DialogObject::create("Darkness", tr("Son mas <cr>dificiles</c> de lo que imaginas. <d90> Dudo que <cb>lo logres</c> antes de que acabe mi <cr>plan</c>.", "They are much <cr>harder</c> than you think. <d90> I doubt you'll <cb>succeed</c> before my <cr>plan</c> is complete.").c_str(), 15, 1, false, { 255, 255, 255 }));
            array->addObject(DialogObject::create("Darkness", tr("Sin mas que decir...", "Without anything else to say...").c_str(), 15, 1, false, { 255, 255, 255 }));
            array->addObject(DialogObject::create("Darkness", tr("<d60> <s250> <cy>Bienvenido</c> </s> <s250>al</s> <s250> <cr>HARD MODE</c>.</s>", "<d60> <s250> <cy>Welcome</c> </s> <s250>to</s> <s250> <cr>HARD MODE</c>.</s>").c_str(), 15, 1, false, { 255, 255, 255 }));


            Mod::get()->setSavedValue<bool>("first-time", true);
        }
        else {
            array->addObject(DialogObject::create(
                "Darkness",
                tr("<d60> <s250> <cr>DEJA DE INSISTIR</c>.</s>", "<d60> <s250> <cr>STOP INSISTING</c>.</s>").c_str(),
                15, 1, false, { 255, 255, 255 }
            ));
        }
        auto dialog = DialogLayer::createDialogLayer(nullptr, array, 5);
        dialog->animateInRandomSide();
        CCScene::get()->addChild(dialog);

    }

    void onMoreGames(CCObject * sender)
    {

        auto creditsLayer = CreditsLayer::create();
        creditsLayer->show();

    }
    void swapTexture(std::string goldKey, std::string userKey) {
        auto textureCache = CCSpriteFrameCache::get();
        auto goldTexture = textureCache->spriteFrameByName(goldKey.c_str());
        textureCache->removeSpriteFrameByName(userKey.c_str());
        textureCache->addSpriteFrame(goldTexture, userKey.c_str());
    }
};