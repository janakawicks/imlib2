#include <gtest/gtest.h>

#include "config.h"
#include <Imlib2.h>

#include "test.h"

TEST(MISC, version)
{
    EXPECT_EQ(imlib_version(), IMLIB2_VERSION);
}

TEST(MISC, strerror)
{
    if (debug <= 0)
        return;

    for (int i = -10; i < 140; i++)
    {
        printf("%3d: '%s'\n", i, imlib_strerror(i));
    }
}

#define CHECK_LOADER(name, have) \
    EXPECT_EQ(imlib_have_loader_for(name), have)
#define CHECK_SAVER(name, have) \
    EXPECT_EQ(imlib_have_saver_for(name), have)

TEST(MISC, loaders)
{
    CHECK_LOADER("png", 1);
    CHECK_LOADER("PNG", 1);
    CHECK_LOADER("PNx", 0);
    CHECK_LOADER("xz", 1);

    CHECK_SAVER("png", 1);
    CHECK_SAVER("PNG", 1);
    CHECK_SAVER("PNx", 0);
    CHECK_SAVER("xz", 0);
}
