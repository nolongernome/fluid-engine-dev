// Copyright (c) 2017 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw_gl3.h>

#include <cmath>

#include <imgui/ImGuiUtils.h>

#include <jet.viz/glfw_imgui_utils-ext.h>
#include <jet.viz/jet.viz.h>
#include <jet/jet.h>

#include <GLFW/glfw3.h>

#include <random>

using namespace jet;
using namespace viz;

// MARK: Macros
#define IX(i, j) ((i) + (sN) * (j))

// MARK: Global variables
<<<<<<< HEAD
static size_t sN = 128;
static Frame sFrame{0, 1.0 / 60.0};
static GridSmokeSolver2Ptr sSolver;
static ImageRenderablePtr sRenderable;
static ByteImage sImage;
static VolumeGridEmitter2Ptr sEmitter;

std::mt19937 sRandomGen(0);
std::uniform_real_distribution<> sRandomDist(0.0, 1.0);
=======
namespace global {

size_t sN = 256 + 2;
float sForce, sSource;
int sDvel;

Frame sFrame{0, 0.1};
experimental::GridFluidSolver2Ptr sSolver;
ImageRenderablePtr sRenderable;
ByteImage sImage;

int sFrameX, sFrameY;
int sMouseDown[2];
int sOmx, sOmy, sMx, sMy;

}  // namespace global

// MARK: Relates mouse movements to forces sources
static void getFromUI(float* d_, float* u_, float* v_) {
    using namespace global;
    int N = (int)sN - 2;
    int i, j, size = (N + 2) * (N + 2);

    for (i = 0; i < size; i++) {
        u_[i] = v_[i] = d_[i] = 0.0f;
    }

    if (!sMouseDown[0] && !sMouseDown[1])
        return;

    i = (int)((sMx / (float)sFrameX) * N + 1);
    j = (int)(((sFrameY - sMy) / (float)sFrameY) * N + 1);

    if (i < 1 || i > N || j < 1 || j > N)
        return;

    if (sMouseDown[0]) {
        u_[IX(i, j)] = sForce * (sMx - sOmx);
        v_[IX(i, j)] = sForce * (sOmy - sMy);
    }

    if (sMouseDown[1]) {
        d_[IX(i, j)] = sSource;
    }

    sOmx = sMx;
    sOmy = sMy;
}
>>>>>>> Rebase build fix

// MARK: Rendering
void densityToImage() {
    using namespace global;
    const auto den = sSolver->density();
    sImage.resize(sN, sN);
    for (size_t i = 0; i < sN; i++) {
        for (size_t j = 0; j < sN; j++) {
<<<<<<< HEAD
            const double d = clamp(2.0f * den(i, j) - 1.0, -1.0, 1.0);
            auto color = ByteColor(Color::makeJet(d));
=======
            const float d = clamp((float)den(i, j), 0.0f, 1.0f);
            const auto bd = static_cast<uint8_t>(d * 255);
            ByteColor color{bd, bd, bd, 255};
>>>>>>> Rebase build fix
            sImage(i, j) = color;
        }
    }
    sRenderable->setImage(sImage);
}

// MARK: Emitter
void resetEmitter() {
    auto sphere = Sphere2::builder()
                      .withCenter({0.2 + 0.6 * sRandomDist(sRandomGen),
                                   0.2 + 0.3 * sRandomDist(sRandomGen)})
                      .withRadius(0.05 + 0.1 * sRandomDist(sRandomGen))
                      .makeShared();
    auto emitter =
        VolumeGridEmitter2::builder().withSourceRegion(sphere).makeShared();
    sSolver->setEmitter(emitter);
    emitter->addStepFunctionTarget(sSolver->smokeDensity(), 0.0, 1.0);
    emitter->addStepFunctionTarget(sSolver->temperature(), 0.0,
                                   1.0 * 0.5 * sRandomDist(sRandomGen));
}

// MARK: Event handlers
bool onKeyDown(GLFWWindow* win, const KeyEvent& keyEvent) {
    switch (keyEvent.key()) {
        case 'q':
        case 'Q':
            exit(EXIT_SUCCESS);
        case GLFW_KEY_ENTER:
            win->setIsAnimationEnabled(!win->isAnimationEnabled());
            return true;
        default:
            break;
    }

    return false;
}

bool onPointerPressed(GLFWWindow* win, const PointerEvent& pointerEvent) {
    using namespace global;
    (void)win;
    int button =
        (pointerEvent.pressedMouseButton() == MouseButtonType::Left) ? 0 : 1;
    sMouseDown[button] = true;
    return true;
}

bool onPointerReleased(GLFWWindow* win, const PointerEvent& pointerEvent) {
    using namespace global;
    (void)win;
    int button =
        (pointerEvent.pressedMouseButton() == MouseButtonType::Left) ? 0 : 1;
    sMouseDown[button] = false;
    return true;
}

bool onPointerDragged(GLFWWindow* win, const PointerEvent& pointerEvent) {
    using namespace global;
    (void)win;
    sMx = (int)pointerEvent.x();
    sMy = (int)pointerEvent.y();
    return true;
}

bool onGui(GLFWWindow*) {
    ImGui_ImplGlfwGL3_NewFrame();
    ImGui::Begin("Info");
    {
        ImGui::Text("Application average %.3f ms/sFrame (%.1f FPS)",
                    1000.0f / ImGui::GetIO().Framerate,
                    ImGui::GetIO().Framerate);
<<<<<<< HEAD

        if (ImGui::Button("Add Source")) {
            resetEmitter();
        }

        auto diff = (float)sSolver->smokeDiffusionCoefficient();
        ImGui::SliderFloat("Smoke Diffusion", &diff, 0.0f, 0.005f, "%.5f");
        sSolver->setSmokeDiffusionCoefficient(diff);

        auto decay = (float)sSolver->smokeDecayFactor();
        ImGui::SliderFloat("Smoke Decay", &decay, 0.0f, 0.01f);
        sSolver->setSmokeDecayFactor(decay);
=======
>>>>>>> [WIP] More Core API tests
    }
    ImGui::End();
    ImGui::Render();
    return true;
}

bool onUpdate(GLFWWindow* win) {
    using namespace global;

    const auto fbSize = win->framebufferSize();
    sFrameX = (int)fbSize.x;
    sFrameY = (int)fbSize.y;

    float* uSrc = sSolver->uSource().data();
    float* vSrc = sSolver->vSource().data();
    float* denSrc = sSolver->densitySource().data();
    getFromUI(denSrc, uSrc, vSrc);

    sSolver->update(sFrame);
    densityToImage();

    ++sFrame;

    return true;
}

int main(int, const char**) {
    using namespace global;

    Logging::mute();

    GLFWApp::initialize();

    // Setup sSolver
<<<<<<< HEAD
    sSolver = GridSmokeSolver2::builder()
                  .withResolution({sN, sN})
                  .withDomainSizeX(1.0)
                  .makeShared();
    auto pressureSolver =
        std::make_shared<GridFractionalSinglePhasePressureSolver2>();
    pressureSolver->setLinearSystemSolver(
        std::make_shared<FdmMgSolver2>(6, 3, 3, 3, 3));
    auto diffusionSolver =
        std::make_shared<GridBackwardEulerDiffusionSolver2>();
    diffusionSolver->setLinearSystemSolver(
        std::make_shared<FdmGaussSeidelSolver2>(10, 10, 1e-3));
    sSolver->setPressureSolver(pressureSolver);
    sSolver->setDiffusionSolver(diffusionSolver);
    resetEmitter();
=======
    sSolver = std::make_shared<experimental::GridFluidSolver2>();
    sSolver->resizeGrid({sN, sN}, {1.0 / sN, 1.0 / sN}, {0.0, 0.0});
    sForce = 5.0f;
    sSource = 100.0f;
    sDvel = 0;
    //    sSolver = GridSmokeSolver2::builder()
    //                  .withResolution({sN, sN})
    //                  .withDomainSizeX(1.0)
    //                  .makeShared();
    //    auto pressureSolver =
    //        std::make_shared<GridFractionalSinglePhasePressureSolver2>();
    //    pressureSolver->setLinearSystemSolver(
    //        std::make_shared<FdmGaussSeidelSolver2>(20, 20, 0.001));
    //    sSolver->setPressureSolver(pressureSolver);
    //    auto sphere =
    //        Sphere2::builder().withCenter({0.5,
    //        0.2}).withRadius(0.15).makeShared();
    //    auto emitter =
    //        VolumeGridEmitter2::builder().withSourceRegion(sphere).makeShared();
    //    sSolver->setEmitter(emitter);
    //    emitter->addStepFunctionTarget(sSolver->smokeDensity(), 0.0, 1.0);
    //    emitter->addStepFunctionTarget(sSolver->temperature(), 0.0, 1.0);
>>>>>>> Rebase build fix

    // Create GLFW window
    GLFWWindowPtr window = GLFWApp::createWindow("Smoke Sim 2D", 512, 512);

    // Setup ImGui binding
    ImGuiForGLFWApp::configureApp();
    ImGuiForGLFWApp::configureWindow(window);
    ImGui::SetupImGuiStyle(true, 0.75f);
    window->setIsAnimationEnabled(true);

    auto camera = std::make_shared<OrthoCamera>(-0.5, 0.5, -0.5, 0.5);
    auto viewController = std::make_shared<OrthoViewController>(camera);
    viewController->enablePan = false;
    viewController->enableZoom = false;
    viewController->enableRotation = false;
    window->setViewController(viewController);

    // Setup renderer
    auto renderer = window->renderer();
    renderer->setBackgroundColor(Color{1, 1, 1, 1});

    // Load sample image renderable
    const ByteImage img(sN, sN, ByteColor::makeBlack());
    sRenderable = std::make_shared<ImageRenderable>(renderer.get());
    sRenderable->setImage(img);
    sRenderable->setTextureSamplingMode(TextureSamplingMode::kLinear);
    renderer->addRenderable(sRenderable);

    // Set up event handlers
    window->onKeyDownEvent() += onKeyDown;
    window->onPointerPressedEvent() += onPointerPressed;
    window->onPointerReleasedEvent() += onPointerReleased;
    window->onPointerDraggedEvent() += onPointerDragged;
    window->onGuiEvent() += onGui;
    window->onUpdateEvent() += onUpdate;

    GLFWApp::run();

    return 0;
}
