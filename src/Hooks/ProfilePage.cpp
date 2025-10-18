#include <Geode/modify/ProfilePage.hpp>

using namespace geode::prelude;

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