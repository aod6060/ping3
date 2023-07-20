#include <ping3/sys.hpp>


namespace render {


    void init() {

    }

    void release() {

    }


    void clear(glm::vec4 clearColor) {
        glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void beginFrame() {

    }

    void endFrame() {

    }
    
    void setProjection(const glm::mat4& m) {

    }

    void setView(const glm::mat4& m) {

    }

    void setModel(const glm::mat4& m) {

    }

    void render() {

    }

}

