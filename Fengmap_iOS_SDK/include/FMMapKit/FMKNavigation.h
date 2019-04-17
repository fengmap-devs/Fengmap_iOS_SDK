//
//  FMKNavigation.h
//  FMMapKit
//
//  Created by smallLabel on 2017/10/20.
//  Copyright © 2017年 Fengmap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMKGeometry.h"
#import "FMKNaviAnalyser.h"
#import "FMKTextNavigation.h"
#import "FMKLineOption.h"

@class FMKMapView, FMKTextNavigationSegment, FMKPointOption, FMKNaviResult, FMKNavigationInfo, FMKLineMarker;

@protocol FMKNavigationDelegate;

/**
 导航路径规划结果
 */
typedef NS_ENUM(NSInteger, FMKAnalyseRouteResult) {

    ///路算成功
    FMKANALYSERESULT_SUCCESS = 1, 
    ///路算失败，原因：没有起点
    FMKANALYSERESULT_NOSTART,           
    ///路算失败，原因：没有终点
    FMKANALYSERESULT_NOEND,
    ///路算失败，原因：计算失败
    FMKANALYSERESULT_CALCULATEFAILURE
};

NS_ASSUME_NONNULL_BEGIN

/**
 导航功能基类
 */
@interface FMKNavigation : NSObject

+ (instancetype)new UNAVAILABLE_ATTRIBUTE;
- (instancetype)init UNAVAILABLE_ATTRIBUTE;

///实现了 FMKNavigationDelegate 协议的类指针
@property (nonatomic, weak, nullable) id<FMKNavigationDelegate>delegate;

///路算结果
@property (nonatomic, readonly, nullable) NSArray<FMKNaviResult *> *naviResults;

///文字导航分析器，文字导航内容可从该属性获取
@property (nonatomic, strong, readonly) FMKTextNavigation *textNavigation;
///地图视图
@property (nonatomic, readonly) FMKMapView *mapView;
///路径规划成功后的路径总长
@property (nonatomic) CGFloat length;

///路径规划完成后画线，每个navigation对象同时只能有一个线标注物，若线显示形式为轨迹线，该属性为空
@property (nonatomic, readonly, nullable) FMKLineMarker *lineMarker;
///路径规划起点坐标
@property (nonatomic, readonly) FMKGeoCoord start;
///路径规划终点坐标
@property (nonatomic, readonly) FMKGeoCoord end;

/**
 是否以轨迹线的形式展现，默认为轨迹线形式，YES
 
 当允许轨迹线时，传入定位坐标或者模拟导航时，会以不同的线型或颜色显示已经走过的路径
 @warning 该属性必须在画线前设置，在画线完成后，设置该属性并不能动态切换普通线和轨迹线
 */
@property (nonatomic, getter=isTraceLineEnabled) BOOL traceLineEnabled;
///轨迹线未经过的路线样式
@property (nonatomic, strong) FMKLineOption *frontLineOption;
///轨迹线已经过的路线样式
@property (nonatomic, strong) FMKLineOption *backLineOption;

/**
 初始化地图导航对象
 该类为基类，请使用子类初始化

 @param mapView 当前显示的地图视图，地图视图不可为空
 @return 地图导航对象
 */
- (instancetype _Nullable)initWithMapView:(FMKMapView *)mapView;

/**
 设置导航的起点坐标
 设置该属性后会自动在相应位置添加默认的图片标注，该图标标注属性可通过setStartOption:方法修改
 默认的图片资源位于FMBundle.bundle中的的start.png图片，也可以直接替换资源修改默认图片
 注意该图片标注物的管理与FMKImageLayer密切相关，若要删除imageLayer时注意图层的tag
 该图片标注物所在图层imageLayer的layerTag默认为-1
 
 @param startPoint 起点坐标
 */
- (void)setStartPoint:(FMKGeoCoord)startPoint;
/**
 设置导航的终点坐标
 设置该属性后会自动在相应位置添加默认的图片标注，该图标标注属性可通过setEndOption:方法修改
 默认的图片资源位于FMBundle.bundle中的的end.png图片，也可以直接替换资源修改默认图片
 注意该图片标注物的管理与FMKImageLayer密切相关，若要删除imageLayer时注意图层的tag
 该图片标注物所在图层imageLayer的layerTag默认为-1
 
 @param endPoint 终点坐标
 */
- (void)setEndPoint:(FMKGeoCoord)endPoint;

/**
 设置起点图片标注属性

 @param startOption 待设置的起点图片标注属性，若为空则采用默认配置
 */
- (void)setStartOption:(FMKPointOption * _Nullable)startOption;
/**
 设置终点图片标注属性
 
 @param endOption 待设置的终点图片标注属性，若为空或不调用则采用默认配置
 */
- (void)setEndOption:(FMKPointOption *_Nullable)endOption;

/**
 在当前显示地图上进行路径规划

 @param routeSetting 路径规划偏好设置
 @return 路径规划结果
 */
- (FMKAnalyseRouteResult)analyseRoute:(FMKRouteSetting)routeSetting;

/**
 设置生成的文字导航语言类型

 @warning 语言的生成依赖路径规划结果，若路径规划结果出错，语言生成失败；即使成功可能也是上次l成功路径规划对应的文字
 @param language 语言类型 目前仅支持简体中文和英文，默认为简体中文
 @return 是否设置成功，若设置语言和当前语言一致返回NO
 */
- (BOOL)setTextNavigationLanguage:(FMKTextNavigationLanguage)language;

/**
 根据路径规划结果绘制线标注

 @warning 当绘制的线为轨迹线时，返回nil
 @return 生成的线标注物，此线标注物受全局的FMKLineLayer的管理
 */
- (FMKLineMarker * _Nullable)drawNaviLine;

/**
 清除所有起终点标注、线标注及路径规划结果，所有属性恢复初始化状态
 注意模拟导航在调用此方法之前必须调用一次stop方法
 */
- (void)clear;

///路算结束后的路段信息
@property (nonatomic, readonly, nullable) NSArray<FMKTextNavigationSegment *> *segments DEPRECATED_MSG_ATTRIBUTE("please use textNavigation.textNavigationSegments");
///路算结束后的文本描述
@property (nonatomic, readonly, nullable) NSArray<NSString *> *describes DEPRECATED_MSG_ATTRIBUTE("please use textNavigation.textNavigationDescriptions");

@end


/**
 导航过程状态回调
 */
@protocol FMKNavigationDelegate <NSObject>

/**
 导航过程

 @param navigation 导航对象
 @param navigationInfo 导航信息
 */
- (void)navigation:(FMKNavigation *_Nonnull)navigation walking:(FMKNavigationInfo *_Nonnull)navigationInfo;

/**
 导航完成回调

 @param navigation 导航对象
 */
- (void)complete:(FMKNavigation *_Nonnull)navigation;

@end

NS_ASSUME_NONNULL_END
