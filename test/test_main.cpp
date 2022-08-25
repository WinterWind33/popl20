/***
    This file is part of popl (program options parser lib)
    Copyright (C) 2015-2021 Johannes Pohl
    Copyright (C) 2022 Andrea Ballestrazzi

    This software may be modified and distributed under the terms
    of the MIT license.  See the LICENSE file for details.
***/

#include <catch2/catch_test_macros.hpp>
#include <popl.hpp>

TEST_CASE("command line", "[functional][command-line-options]")
{
    using namespace popl;
    using namespace std;

    OptionParser op("Allowed options");
    std::vector<const char*> args = {"popl", "-h"};

    auto help_option = op.add<Switch>("h", "help", "produce help message");
    auto int_option = op.add<Value<int>>("i", "int", "test for int value", 42);

    try
    {
        op.parse(static_cast<int>(args.size()), args.data());
        REQUIRE(help_option->count() == 1);
        REQUIRE(int_option->is_set() == false);
        REQUIRE(int_option->count() == 0);
        REQUIRE(int_option->value() == 42);
    }
    catch (const std::exception& e)
    {
        cerr << "Exception: " << e.what() << "\n";
    }
}

TEST_CASE("config file", "[functional][configuration-file-options]")
{
    using namespace popl;
    using namespace std;

    OptionParser op("Allowed options");
    auto int_option = op.add<Value<int>>("i", "section.integer", "test for int value", 42);

    try
    {
        op.parse("test.conf");
        REQUIRE(int_option->is_set() == true);
        REQUIRE(int_option->count() == 1);
        REQUIRE(int_option->value() == 23);
    }
    catch (const std::exception& e)
    {
        cerr << "Exception: " << e.what() << "\n";
    }
}

