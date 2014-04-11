//
//  UMShareButton.h
//  Umeng Social SDK ShareButton
//
//  Created by mrsimple on 3/18/14.
//
//

#ifndef __crossdemo__UMShareButton__
#define __crossdemo__UMShareButton__

#include <iostream>
#include "cocos2d.h"
#include "CCUMSocialSDK.h"
#include <vector>

USING_NS_CC;
using namespace std;


namespace umeng
{
    namespace social 
    {
        #ifdef CC_CALLBACK_1
            class UMShareButton : public cocos2d::MenuItemImage 
            {
        #else
            class UMShareButton : public cocos2d::CCMenuItemImage 
            {
        #endif
        public:
            virtual  ~UMShareButton() ;

            /** creates a menu item with a normal and selected image*/
            static UMShareButton* create(const char *normalImage, const char *selectedImage, ShareEventHandler callback);
            
            // // 设置友盟app key
            void setUmengAppkey(const char* appkey);
            // 设置文本内容
            void setShareContent(const char* text);
            // 可以设置本地图片和url图片, url图片必须以http://开头
            void setShareImage(const char* imgName);
            // 设置分享回调
            void setShareCallback(ShareEventHandler callback);
            // 设置分享面板上的平台
            void setPlatforms(vector<int>* platforms);
            // 获取CCUMSocialSDK对象
            CCUMSocialSDK* getSocialSDK();

        private:
            UMShareButton();
            // 构造函数
            UMShareButton(const char *normalImage, const char *selectedImage);
            // 打开分享面板
            void openShareBoard();
        #ifdef CC_CALLBACK_1
            // 分享按钮回调, 打开友盟分享面板
            void shareCallback(cocos2d::Ref* pSender);
        #else 
             // 分享按钮回调, 打开友盟分享面板
            void shareCallback(CCNode* pSender);
        #endif
           
        private:
            // 友盟分享组件SDK
            CCUMSocialSDK* mSocialSDK;
            // 要添加支持的平台
            vector<int>* mPlatforms;
            // 要分享的文本内容
            string mShareText;
            // 要分享的图片本地路径或者url
            string mImageName;
            // 友盟的appkey
            string mAppKey;
            // 分享回调
            ShareEventHandler mCallback ;
        };
    }
}

#endif /* defined(__crossdemo__UMShareButton__) */
