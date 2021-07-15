﻿#pragma once

#include "simplecs/components.hpp"

namespace eld::impl
{
    template<typename ClassType>
    typename component_c<ClassType>::component_descriptor_type
        component_c<ClassType>::component_descriptor()
    {
        static c_context context{};
        return context.descriptor().componentDescriptor;
    }

    template<typename ClassType>
    component_c<ClassType>::c_context::c_context()
    {
        // TODO: errors, params
        [[maybe_unused]] auto error =
            c_api::init_component_storage(descriptor_, c_api::storage_params{ sizeof(type) });
    }

    template<typename ClassType>
    component_c<ClassType>::c_context::~c_context()
    {
        [[maybe_unused]] auto error = c_api::release_component_storage(descriptor_);
    }

    template<typename ClassType>
    c_api::component_storage_descriptor component_c<ClassType>::c_context::descriptor() const
    {
        return descriptor_;
    }

}   // namespace eld::impl
