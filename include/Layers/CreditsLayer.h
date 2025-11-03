#pragma once
#include <Geode/Geode.hpp>
using namespace geode::prelude;

class CreditsLayer : public geode::Popup<>
{
protected:
    bool setup() override;
public:
    static CreditsLayer* create();
    void createProfilePlaceholder(CCLayer* layer,const char* username, int color1, int color2, int colorGlow,int iconID, int accountID,CCPoint position);
	void toProfile(CCObject* sender);
};