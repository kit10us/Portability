/*
 * Unify Library
 * https://github.com/kit10us/unify
 * Copyright (c) 2002, Kit10 Studios LLC
 *
 * This file is part of Unify Library (a.k.a. Unify)
 *
 * Unify is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Unify is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Unify.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <gtest/gtest.h>

#include <port/Port.h>
#include <port/Platform.h>

class PlatformTests : public ::testing::Test
{ 
protected:
    void SetUp() override
    {
        // Code here will be called immediately after the constructor (right before each test).
    }

    void TearDown() override
    {
        // Code here will be called immediately after each test (right before the destructor).
    }  
};

#if defined(PORT_WINDOWS)

/// @brief
/// Verify platform generation is working. 
/// This is a test to ensure that the platform generation is functioning correctly and that the 
/// testing framework is set up properly.
TEST_F(PlatformTests, PlatformGeneration)
{
    auto platform = port::GeneratePlatform();
    ASSERT_NE(platform, nullptr);
    ASSERT_STREQ(platform->GetOS().c_str(), "Windows");
    ASSERT_STREQ(platform->GetBuildTarget().c_str(), "Debug");
}

#endif