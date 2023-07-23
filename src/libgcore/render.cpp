#include <gcore/sys.hpp>


namespace render {

    // Shaders
    static uint32_t main_vs = 0;
    static uint32_t main_fs = 0;

    // Program
    static uint32_t main_p = 0;
    static uint32_t u_proj = 0;
    static uint32_t u_view = 0;
    static uint32_t u_model = 0;

    // Vertex Array
    static uint32_t main_va = 0;
    static uint32_t VERTICES = 0;


    static std::vector<glm::vec3> vertices;
    static uint32_t vertices_vbo = 0;

    static std::vector<uint32_t> inds;
    static uint32_t inds_vbo = 0;

    uint32_t createShader(GLenum type, std::string path);
    uint32_t createProgram(const std::vector<uint32_t>& shaders);

    void init() {

        // Shader
        main_vs = createShader(GL_VERTEX_SHADER, "./data/shaders/main.vert.glsl");
        main_fs = createShader(GL_FRAGMENT_SHADER, "./data/shaders/main.frag.glsl");

        // Program
        main_p = createProgram({
            main_vs,
            main_fs
        });

        // Vertex Array
        glGenVertexArrays(1, &main_va);

        glUseProgram(main_p);

        // Uniform
        u_proj = glGetUniformLocation(main_p, "u_proj");
        u_view = glGetUniformLocation(main_p, "u_view");
        u_model = glGetUniformLocation(main_p, "u_model");

        // Vertex Array
        glBindVertexArray(main_va);
        glEnableVertexAttribArray(VERTICES);
        glBindVertexArray(0);

        glUseProgram(0);


        // Vertices
        vertices.push_back(glm::vec3(0.0f, 0.0f, 0.0f));
        vertices.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
        vertices.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
        vertices.push_back(glm::vec3(1.0f, 1.0f, 0.0f));

        glGenBuffers(1, &vertices_vbo);

        glBindBuffer(GL_ARRAY_BUFFER, vertices_vbo);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_DYNAMIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        // Inds
        inds = {
            0, 1, 2,
            2, 1, 3
        };
	
	glGenBuffers(1, &inds_vbo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, inds_vbo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, inds.size() * sizeof(uint32_t), inds.data(), GL_DYNAMIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    void release() {
        glDeleteBuffers(1, &inds_vbo);
        glDeleteBuffers(1, &vertices_vbo);

        glDeleteVertexArrays(1, &main_va);

        std::vector<uint32_t> shaders = {
            main_vs,
            main_fs
        };

        std::for_each(shaders.begin(), shaders.end(), [](uint32_t id) {
            glDetachShader(main_p, id);
        });

        glDeleteProgram(main_p);
        glDeleteShader(main_fs);
        glDeleteShader(main_vs);
    }

    void clear(glm::vec4 clearColor) {
        glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void beginFrame() {
        glUseProgram(main_p);
    }

    void endFrame() {
        glUseProgram(0);
    }
    
    void setProjection(const glm::mat4& m) {
        glUniformMatrix4fv(u_proj, 1, GL_FALSE, &m[0][0]);
    }

    void setView(const glm::mat4& m) {
        glUniformMatrix4fv(u_view, 1, GL_FALSE, &m[0][0]);
    }

    void setModel(const glm::mat4& m) {
        glUniformMatrix4fv(u_model, 1, GL_FALSE, &m[0][0]);
    }

    void render() {
        glBindVertexArray(main_va);

        glBindBuffer(GL_ARRAY_BUFFER, vertices_vbo);
        glVertexAttribPointer(VERTICES, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, inds_vbo);
        glDrawElements(GL_TRIANGLES, inds.size(), GL_UNSIGNED_INT, nullptr);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        glBindVertexArray(0);
    }


    uint32_t createShader(GLenum type, std::string path) {
        uint32_t temp = glCreateShader(type);

        std::stringstream ss;

        util::loadFile(path, [&](std::string line) {
            ss << line << "\n";
        });

        std::string src = ss.str();
        const char* c_src = src.c_str();

        glShaderSource(temp, 1, &c_src, nullptr);

        glCompileShader(temp);

        int len = 0;

        glGetShaderiv(temp, GL_INFO_LOG_LENGTH, &len);

        if(len > 0) {
            std::string log;
            log.resize(len);
            glGetShaderInfoLog(temp, log.size(), nullptr, log.data());
            logger::output(logger::LoggerType::LT_ERROR, [&](std::stringstream& ss) {
                ss << "\n";
                ss << log;
                ss << "\n";
            });
            log.clear();
        }

        return temp;
    }

    uint32_t createProgram(const std::vector<uint32_t>& shaders) {
        uint32_t temp = glCreateProgram();

        std::for_each(shaders.begin(), shaders.end(), [&](uint32_t id) {
            glAttachShader(temp, id);
        });

        glLinkProgram(temp);

        int len = 0;

        glGetProgramiv(temp, GL_INFO_LOG_LENGTH, &len);

        if(len > 0) {
            std::string log;
            log.resize(len);
            glGetProgramInfoLog(temp, log.size(), nullptr, log.data());
            logger::output(logger::LoggerType::LT_ERROR, [&](std::stringstream& ss) {
                ss << "\n";
                ss << log;
                ss << "\n";
            });
            log.clear();
        }

        return temp;
    }
}
