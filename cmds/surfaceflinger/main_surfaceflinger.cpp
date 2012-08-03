/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <binder/BinderService.h>
#include <SurfaceFlinger.h>

#ifdef OMAP_ENHANCEMENT_S3D
#include <S3DSurfaceFlinger.h>
#endif

using namespace android;

int main(int argc, char** argv) {
#ifdef OMAP_ENHANCEMENT_S3D
    BinderService<S3DSurfaceFlinger>::publishAndJoinThreadPool();
#else
    SurfaceFlinger::publishAndJoinThreadPool(true);
#endif
    // When SF is launched in its own process, limit the number of
    // binder threads to 4.
    ProcessState::self()->setThreadPoolMaxThreadCount(4);
    return 0;
}
