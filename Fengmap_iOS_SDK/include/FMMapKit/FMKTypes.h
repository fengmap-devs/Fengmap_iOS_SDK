//
//  FMKTypes.h
//  FMMapKit
//
//  Created by mac on 2019/1/7.
//  Copyright © 2019 Fengmap. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Fengmap地图加载错误码
 */
typedef NS_ENUM(NSInteger, FMKErrorCodeType) {
    /// 网络错误
    FMKErrorCodeType_NET_ERROR                  = 1,
    /// key错误
    FMKErrorCodeType_KEY_ERROR                  = 2,
    /// mapID错误
    FMKErrorCodeType_MAPID_ERROR                = 3,
    /// 没有权限访问数据
    FMKErrorCodeType_NO_PERMISSION              = 4,
    /// key与bundleID不匹配
    FMKErrorCodeType_KEY_NO_MATCH_BUNDLEID      = 5,
    /// 地图数据解析失败
    FMKErrorCodeType_MAPDATA_PARSE_ERROR        = 6,
    /// 地图数据下载失败
    FMKErrorCodeType_DOWNLOAD_ERROR             = 7,
    /// 没有版本号错误
    FMKErrorCodeType_NO_VERSION_INFO            = 8,
    /// 地图文件路径错误
    FMKErrorCodeType_MAP_DATA_DIRECTORY_ERROR   = 9,
    /// 版本号解析失败
    FMKErrorCodeType_MAP_VERSION_PARSE_ERROR    = 10,
    /// 未知错误
    FMKErrorCodeType_UNKNOWN_ERROR              = 11,
    /// license错误
    FMKErrorCodeType_LICENSE_ERROR              = 12,
};


/**
 线标注类型
 */
typedef NS_ENUM(NSInteger,FMKLineType)
{
    /// 实线
    FMKLINE_FULL = 0,
    /// 点线 1000100010001000, 表示实际画线的点
    FMKLINE_DOTTED,
    /// 点划线    1111111111100100  dot dash.  .  .  .  .  .  .  .  .  .  .  .  .  .
    FMKLINE_DOTDASH,
    /// 中心线    1111111111001100  centre line ____ . ____ . _____ . _____. _____
    FMKLINE_CENTER,
    /// 虚线  1111110011111100   dashed_____ _ _____ _ _____ _ _____ _ _____
    FMKLINE_DASHED,
    /// 双点划线  1111111100100100  double dot dash____  ____  ____  ____  ____  ____  ____
    FMKLINE_DOUBLEDOTDASH,
    /// 三点划线  111111110101010 tri_dot_dash ____ . . ____ . . ____ . . ____ . . ____
    FMKLINE_TRIDOTDASH,
    /// 动态跨层线段
    FMKLINE_TEXTURE,
    /// 默认线型
    FMKLINE_TEXTURE_NORMAL
};

/**
 *  线段大小类型
 */
typedef NS_ENUM(NSInteger, FMKLineMode){
    /**
     *  像素宽度模式 不随放大缩小改变宽度 注：deprecated
     */
    FMKLINE_PIXEL   = 0 ,
    /**
     *  空间宽度模式 随放大缩小变化宽度，推荐使用该模式
     */
    FMKLINE_PLANE   = 1,
    /**
     *  管状模式
     */
    FMKLINE_CIRCLE  = 2
};


/**
 *  图片位于地图上的位置
 */
typedef NS_ENUM(NSInteger, FMKImageMarkerOffsetMode){
    /**
     *  位于建筑模型之上
     */
    FMKImageMarker_MODELTOP = 0,
    /**
     *  位于地面之上
     */
    FMKImageMarker_OVEREXTENT,
    
    /**
     *  用户自定义
     */
    FMKImageMarker_USERDEFINE
};


/**
 图片绘制模式
 
 - FMKImageMarker_NORMAL: 默认模式
 - FMKImageMarker_BILLBOARD: 广告版模式
 */
typedef NS_ENUM(NSInteger, FMKImageMarkerRenderMode)
{
    ///默认模式
    FMKImageMarker_NORMAL = 0,
    ///广告版模式
    FMKImageMarker_BILLBOARD
};

/**
 *  覆盖面标注物偏移模式
 */
typedef NS_ENUM(NSInteger,FMKPolygonMarkerOffsetMode) {
    /**
     *  位于模型之上
     */
    FMKPolygonMarker_MODELTOP = 0,
    /**
     *  位于底面之上
     */
    FMKPolygonMarker_OVEREXTENT,
    /**
     *  用户自定义 当选择这个模式时，需要设置标注物的偏移量
     */
    FMKPolygonMarker_USERDEFINE
};
/**
 *  多边形形状
 */
typedef NS_ENUM(NSInteger, FMKPolygonMarkerType) {
    /**
     *  普通形状
     */
    FMKPolygonMarker_NORMAL = 0,
    /**
     *  矩形
     */
    FMKPolygonMarker_RECTANGLE,
    /**
     *  圆
     */
    FMKPolygonMarker_CIRCLE
};

/**
 *  文本位于地图上的位置
 */
typedef NS_ENUM(NSInteger, FMKTextOffsetMode){
    /**
     *  位于模型之上
     */
    FMKTextMarker_MODELTOP = 0,
    /**
     *  位于地面之上
     */
    FMKTextMarker_OVEREXTENT,
    
    /**
     *  用户自定义
     */
    FMKTextMarker_USERDEFINE
};



/**
 路径规划策略
 */
typedef NS_ENUM(NSInteger, FMKNaviModule)
{
    /// 最短路径策略
    MODULE_SHORTEST = 1,
    /// 最优路径策略
    MODULE_BEST = 2,
};

/**
 楼层间路径规划方式优先级
 */
typedef NS_ENUM(NSInteger, FMKRouteCrossGroupPriority)
{
    ///默认直梯优先方式
    FMKROUTE_CGP_DEFAULT = 0,//LIFT > ESCALATOR > STAIR
    ///直梯优先
    FMKROUTE_CGP_LIFTFIRST,
    ///扶梯优先
    FMKROUTE_CGP_ESCALATORFIRST,
    ///楼梯优先
    FMKROUTE_CGP_STAIRFIRST,
    ///仅直梯
    FMKROUTE_CGP_LIFTONLY,
    ///仅扶梯
    FMKROUTE_CGP_ESCALATORONLY,
    ///仅楼梯
    FMKROUTE_CGP_STAIRONLY
};

/**
 路径分析类型设置
 */
typedef struct FMKRouteSetting
{
    /*
     *    路径经过楼梯优先级选择
     */
    FMKRouteCrossGroupPriority routeCrossGroupPriority;
    /*
     *    最短最优路径计算方法选择
     */
    FMKNaviModule naviModule;
    
}FMKRouteSetting;

/**
 * 路径计算的返回值。
 */
typedef NS_ENUM(NSInteger, FMKRouteCalculateResultType)
{
    ///地图数据不存在
    IROUTE_DATA_LOST = -3,
    ///数据库出错
    IROUTE_DATABASE_ERROR = -2,
    ///数据错误
    IROUTE_PARAM_ERROR = -1,
    ///成功
    IROUTE_SUCCESS = 1,
    ///与数据无关的错误
    IROUTE_FAILURE_NO_FMDBKERNEL = 2,
    ///失败，起点和终点太近
    IROUTE_FAILURE_TOO_CLOSE = 3,
    ///失败，没有起点所在层的数据
    IROUTE_FAILURE_NO_START = 4,
    ///失败，没有终点所在层的数据
    IROUTE_FAILURE_NO_END = 5,
    ///失败，没有电梯（扶梯）进行跨楼路径规划
    IROUTE_FAILURE_NO_STAIR_FLOORS = 6,
    ///失败，不支持跨楼层导航
    IROUTE_FAILURE_NOTSUPPORT_FLOORS = 7,
    ///不能计算
    IROUTE_FAILED_CANNOT_CALCULATE = 8,
    ///没有结果
    IROUTE_SUCCESS_NO_RESULT = 9
};


@interface FMKTypes : NSObject

@end

NS_ASSUME_NONNULL_END
