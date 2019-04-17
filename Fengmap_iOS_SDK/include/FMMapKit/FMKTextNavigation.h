//
//  FMKTextNavigation.h
//  FMMapKit
//
//  Created by mac on 2018/12/20.
//  Copyright © 2018 Fengmap. All rights reserved.
//

#import <Foundation/Foundation.h>
@class FMKTextNavigationSegment;
@class FMKNaviResult;

NS_ASSUME_NONNULL_BEGIN

typedef NSString * FMKTextNavigationLanguage NS_STRING_ENUM;

FOUNDATION_EXTERN const FMKTextNavigationLanguage FMKTextNavigationLanguageChinese;
FOUNDATION_EXTERN const FMKTextNavigationLanguage FMKTextNavigationLanguageEnglish;


/**
 文字导航分析类
 
 使用路径规划结果生成对应的文字描述和对应的路段对象集合，支持中英文切换
 */
@interface FMKTextNavigation : NSObject

/**
 文字导航描述，目前支持简体中文和英文，可通过- setTextNavigationLanguage:方法改变生成语言类型
 */
@property (nonatomic, strong, readonly) NSArray<NSString *> *textNavigationDescriptions;

/**
 文字导航路段生成
 
 @warning 该路段是过滤了路径规划结果的点集构成的线段
 */
@property (nonatomic, strong, readonly) NSArray<FMKTextNavigationSegment *> *textNavigationSegments;

/**
 初始化时传入的路径规划结果
 */
@property (nonatomic, readonly) NSArray<FMKNaviResult *> *naviResults;

/**
 构造方法

 @param naviResults 路径规划结果，若数组内容为空，初始化失败
 @param mapPath 对应地图数据路径，若路径下文件不存在，初始化失败
 @return 文字导航生成器
 */
+ (instancetype)textaNavigationWithNaviResuls:(NSArray<FMKNaviResult *> *)naviResults mapPath:(NSString *)mapPath;

/**
 构造方法

 @param naviResults 路径规划结果 若数组内容为空，初始化失败
 @param mapPath 对应地图数据路径，若路径下文件不存在，初始化失败
 @return 文字导航生成器
 */
- (instancetype)initWithNaviResults:(NSArray *)naviResults mapPath:(NSString *)mapPath;

/**
 

 @param language
 */

/**
 设置生成的文字语言，目前支持支持简体中文和英文，语言类型 FMKTextNavigationLanguage,默认为FMKTextNavigationLanguageChinese简体中文
 调用该方法会触发导航文字生成逻辑，修改已经生成的文字内容为设定语言，更新内容在textNavigationDescriptions属性和textNavigationSegments属性

 @param language 语言类型
 @return 语言类型是否设置成功 若语言不匹配或与上次                            
 */
- (BOOL)setTextNavigationLanguage:(FMKTextNavigationLanguage)language;

/**
 生成相应的文字导航，文字导航结果可在 textNavigationDescriptions 属性中查看
 同时会生成相应的路段信息，路段信息可在 textNavigationSegments 属性中查看
 */
- (void)generateTextNavigationDescriptions;

@end

NS_ASSUME_NONNULL_END
