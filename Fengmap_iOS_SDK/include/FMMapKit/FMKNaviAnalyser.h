//
//  FMNaviAnalyser.h
//  FMMapKit
//
//  Created by FengMap on 15/6/1.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMKGeometry.h"
#import "FMKTypes.h"

@class FMKTextNavigationSegment;
@class FMKNaviResult;

@protocol FMKNaviAnalyserDelegate;

NS_ASSUME_NONNULL_BEGIN
/**
 路径规划分析器
 
 @warning 该实例对象在调用过程中非线程安全
 */
@interface FMKNaviAnalyser : NSObject

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

/**
 *  通过mapID初始化路径分析
 *	通过该方式初始化路径分析对象时，地图数据必须是通过ID下载得到的，否则会初始化失败
 *  地图数据下载有两种方式：一、通过id加载过地图数据会自动下载；二、使用SDK下载器下载地图数据
 *
 *  @param mapID 地图id
 *
 *  @return 路径分析对象
 */
- (instancetype)initWithMapID:(NSString *)mapID;

/**
 *  通过地图数据路径初始化路径分析
 *
 *  @param dataPath 地图数据路径
 *
 *  @return 路径分析对象
 */
- (instancetype)initWithMapPath:(NSString *)dataPath;

/**
 *  路径规划分析代理
 */
@property (nonatomic,weak)  id<FMKNaviAnalyserDelegate> delegate;

/**
 路径规划分析
 该方法仅计算路算长度，不返回路段结果，也不会生成相应文字描述

 @param start 路径规划起点
 @param end 路径规划终点
 @param routeSetting 路算策略
 @return 路径规划计算结果
 */
- (FMKRouteCalculateResultType)analyseRouteWithStartCoord:(FMKGeoCoord)start
                                                 endCoord:(FMKGeoCoord)end
                                                     type:(FMKRouteSetting)routeSetting;

/**
 路径规划分析
 该方法会生成相应路段文字描述
 @param start 路径规划起点
 @param end 路径规划终点
 @param routeSetting 路算策略
 @param naviResults 路径规划结果，对象为FMKNaviResult型对象
 @return 路径规划计算结果
 */
- (FMKRouteCalculateResultType)analyseRouteWithStartCoord:(FMKGeoCoord)start
                                                      end:(FMKGeoCoord)end
                                                     type:(FMKRouteSetting)routeSetting
                                              routeResult:(NSMutableArray *__autoreleasing*)naviResults;
#pragma mark- deprecated
/**
 文字导航处理结果 路径规划有结果时有效
 
 @warning deprecated
 */
@property (nonatomic, readonly) NSArray <FMKTextNavigationSegment *>* naviDescriptionsData  DEPRECATED_MSG_ATTRIBUTE("use FMKTextNavigation.h textNavigationSegments");

/**
 文字导航文字描述 路径规划有结果时有效
 
 @warning deprecated
 */
@property (nonatomic, readonly) NSArray <NSString *>* naviDescriptions DEPRECATED_MSG_ATTRIBUTE("use FMKTextNavigation.h textNavigationDescriptions");
@end


/**
 路径规划回调方法
 */
@protocol FMKNaviAnalyserDelegate <NSObject>

@optional

/**
 路径规划成功后相应楼层的点集合，若路径规划有多个楼层，该回调会触发多次

 @param analyser 路径分析器
 @param coords 对应楼层路径规划结果点集合
 @param groupID 楼层id
 */
- (void)analyser:(FMKNaviAnalyser *)analyser naviGeoCoords:(NSArray *)coords inGroup:(NSString *)groupID;

/**
 路径规划成功后对应楼层的路径长度，若路径规划有多个楼层，该回调会触发多次

 @param analyser 路径分析器
 @param length 对应楼层上的路径长度
 @param groupID 楼层id
 */
- (void)analyser:(FMKNaviAnalyser *)analyser groupLength:(double)length inGroup:(NSString *)groupID;

/**
 路径规划结果包含的所有楼层id

 @param analyser 路径分析器
 @param groupIDs 路径规划结果包含的所有楼层id，若为跨层路径规划，该集合可能包含重复楼层id，且 仅包含起点和终点所在楼层id
 */
- (void)analyser:(FMKNaviAnalyser *)analyser groupIDs:(NSArray *)groupIDs;

/**
 路径规划总长度

 @param analyser 路径分析器
 @param totalLength 路径总长度
 */
- (void)analyser:(FMKNaviAnalyser *)analyser totalLength:(double)totalLength;
@end

NS_ASSUME_NONNULL_END


