#include "nw4r/lyt/lyt_picture.hpp"
#include "nw4r/lyt/lyt_layout.hpp"

namespace nw4r {
    namespace lyt {
        void Picture::Init(u8 texNum) {
            if (texNum > 0) {
                ReserveTexCoord(texNum);
            }
        }

        Picture::~Picture() {
            if (mpMaterial == nullptr && mpMaterial->mbUserAllocated == false) {
                Layout::DeleteObj(mpMaterial);
                mpMaterial = nullptr;
            }

            mTexCoordAry.Free();
        }
    }; 
};