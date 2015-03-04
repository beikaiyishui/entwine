/******************************************************************************
* Copyright (c) 2016, Connor Manning (connor@hobu.co)
*
* Entwine -- Point cloud indexing
*
* Entwine is available under the terms of the LGPL2 license. See COPYING
* for specific license text and more information.
*
******************************************************************************/

#pragma once

#include <cstdint>
#include <vector>

#include <pdal/PointContext.hpp>

#include "json/json.h"
#include "dim-info.hpp"

class Schema
{
public:
    explicit Schema(std::vector<DimInfo> dims);

    std::size_t stride() const;
    const std::vector<DimInfo>& dims() const;

    pdal::PointContextRef pointContext() const;

    Json::Value toJson() const;
    static Schema fromJson(const Json::Value& json);

private:
    const std::vector<DimInfo> m_dims;
    const pdal::PointContext m_pointContext;
};

