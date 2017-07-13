#include <gtest/gtest.h>

#include <TVector3.h>

#include <Exception.h>
#include <RKTrackRep.h>
#include <ConstField.h>
#include <FieldManager.h>
#include <StateOnPlane.h>
#include <SharedPlanePtr.h>
#include <MeasurementOnPlane.h>


namespace genfit {

    class RKTrackRepTests : public ::testing::Test {

    protected:
        virtual void SetUp() {
            const double bFieldZ = 20;  // kGauss. Is 1.5T
            m_constField = new genfit::ConstField(0., 0., bFieldZ);
            genfit::FieldManager::getInstance()->init(m_constField);
        }
        virtual void TearDown() {
            genfit::FieldManager::getInstance()->destruct();
        }
        genfit::ConstField* m_constField;
    };

    TEST_F (RKTrackRepTests, RKStep) {
        genfit::RKStep myRKStep;

        EXPECT_EQ(0, myRKStep.state7_[0]);
        EXPECT_EQ(0, myRKStep.state7_[1]);
        EXPECT_EQ(0, myRKStep.state7_[2]);
        EXPECT_EQ(0, myRKStep.state7_[3]);
        EXPECT_EQ(0, myRKStep.state7_[4]);
        EXPECT_EQ(0, myRKStep.state7_[5]);
        EXPECT_EQ(0, myRKStep.state7_[6]);
    }

    TEST_F (RKTrackRepTests, ExtrapStep) {
        genfit::ExtrapStep myExtrapStep;

        EXPECT_EQ(0, myExtrapStep.jac7_(0, 0));
        EXPECT_EQ(0, myExtrapStep.jac7_(0, 1));
        EXPECT_EQ(0, myExtrapStep.jac7_(0, 2));
        EXPECT_EQ(0, myExtrapStep.jac7_(0, 3));
        EXPECT_EQ(0, myExtrapStep.jac7_(0, 4));
        EXPECT_EQ(0, myExtrapStep.jac7_(0, 5));
        EXPECT_EQ(0, myExtrapStep.jac7_(0, 6));

        EXPECT_EQ(0, myExtrapStep.jac7_(1, 0));
        EXPECT_EQ(0, myExtrapStep.jac7_(1, 1));
        EXPECT_EQ(0, myExtrapStep.jac7_(1, 2));
        EXPECT_EQ(0, myExtrapStep.jac7_(1, 3));
        EXPECT_EQ(0, myExtrapStep.jac7_(1, 4));
        EXPECT_EQ(0, myExtrapStep.jac7_(1, 5));
        EXPECT_EQ(0, myExtrapStep.jac7_(1, 6));

        EXPECT_EQ(0, myExtrapStep.jac7_(2, 0));
        EXPECT_EQ(0, myExtrapStep.jac7_(2, 1));
        EXPECT_EQ(0, myExtrapStep.jac7_(2, 2));
        EXPECT_EQ(0, myExtrapStep.jac7_(2, 3));
        EXPECT_EQ(0, myExtrapStep.jac7_(2, 4));
        EXPECT_EQ(0, myExtrapStep.jac7_(2, 5));
        EXPECT_EQ(0, myExtrapStep.jac7_(2, 6));

        EXPECT_EQ(0, myExtrapStep.jac7_(3, 0));
        EXPECT_EQ(0, myExtrapStep.jac7_(3, 1));
        EXPECT_EQ(0, myExtrapStep.jac7_(3, 2));
        EXPECT_EQ(0, myExtrapStep.jac7_(3, 3));
        EXPECT_EQ(0, myExtrapStep.jac7_(3, 4));
        EXPECT_EQ(0, myExtrapStep.jac7_(3, 5));
        EXPECT_EQ(0, myExtrapStep.jac7_(3, 6));

        EXPECT_EQ(0, myExtrapStep.jac7_(4, 0));
        EXPECT_EQ(0, myExtrapStep.jac7_(4, 1));
        EXPECT_EQ(0, myExtrapStep.jac7_(4, 2));
        EXPECT_EQ(0, myExtrapStep.jac7_(4, 3));
        EXPECT_EQ(0, myExtrapStep.jac7_(4, 4));
        EXPECT_EQ(0, myExtrapStep.jac7_(4, 5));
        EXPECT_EQ(0, myExtrapStep.jac7_(4, 6));

        EXPECT_EQ(0, myExtrapStep.jac7_(5, 0));
        EXPECT_EQ(0, myExtrapStep.jac7_(5, 1));
        EXPECT_EQ(0, myExtrapStep.jac7_(5, 2));
        EXPECT_EQ(0, myExtrapStep.jac7_(5, 3));
        EXPECT_EQ(0, myExtrapStep.jac7_(5, 4));
        EXPECT_EQ(0, myExtrapStep.jac7_(5, 5));
        EXPECT_EQ(0, myExtrapStep.jac7_(5, 6));

        EXPECT_EQ(0, myExtrapStep.jac7_(6, 0));
        EXPECT_EQ(0, myExtrapStep.jac7_(6, 1));
        EXPECT_EQ(0, myExtrapStep.jac7_(6, 2));
        EXPECT_EQ(0, myExtrapStep.jac7_(6, 3));
        EXPECT_EQ(0, myExtrapStep.jac7_(6, 4));
        EXPECT_EQ(0, myExtrapStep.jac7_(6, 5));
        EXPECT_EQ(0, myExtrapStep.jac7_(6, 6));

        EXPECT_EQ(0, myExtrapStep.noise7_(0, 0));
        EXPECT_EQ(0, myExtrapStep.noise7_(0, 1));
        EXPECT_EQ(0, myExtrapStep.noise7_(0, 2));
        EXPECT_EQ(0, myExtrapStep.noise7_(0, 3));
        EXPECT_EQ(0, myExtrapStep.noise7_(0, 4));
        EXPECT_EQ(0, myExtrapStep.noise7_(0, 5));
        EXPECT_EQ(0, myExtrapStep.noise7_(0, 6));

        EXPECT_EQ(0, myExtrapStep.noise7_(1, 0));
        EXPECT_EQ(0, myExtrapStep.noise7_(1, 1));
        EXPECT_EQ(0, myExtrapStep.noise7_(1, 2));
        EXPECT_EQ(0, myExtrapStep.noise7_(1, 3));
        EXPECT_EQ(0, myExtrapStep.noise7_(1, 4));
        EXPECT_EQ(0, myExtrapStep.noise7_(1, 5));
        EXPECT_EQ(0, myExtrapStep.noise7_(1, 6));

        EXPECT_EQ(0, myExtrapStep.noise7_(2, 0));
        EXPECT_EQ(0, myExtrapStep.noise7_(2, 1));
        EXPECT_EQ(0, myExtrapStep.noise7_(2, 2));
        EXPECT_EQ(0, myExtrapStep.noise7_(2, 3));
        EXPECT_EQ(0, myExtrapStep.noise7_(2, 4));
        EXPECT_EQ(0, myExtrapStep.noise7_(2, 5));
        EXPECT_EQ(0, myExtrapStep.noise7_(2, 6));

        EXPECT_EQ(0, myExtrapStep.noise7_(3, 0));
        EXPECT_EQ(0, myExtrapStep.noise7_(3, 1));
        EXPECT_EQ(0, myExtrapStep.noise7_(3, 2));
        EXPECT_EQ(0, myExtrapStep.noise7_(3, 3));
        EXPECT_EQ(0, myExtrapStep.noise7_(3, 4));
        EXPECT_EQ(0, myExtrapStep.noise7_(3, 5));
        EXPECT_EQ(0, myExtrapStep.noise7_(3, 6));

        EXPECT_EQ(0, myExtrapStep.noise7_(4, 0));
        EXPECT_EQ(0, myExtrapStep.noise7_(4, 1));
        EXPECT_EQ(0, myExtrapStep.noise7_(4, 2));
        EXPECT_EQ(0, myExtrapStep.noise7_(4, 3));
        EXPECT_EQ(0, myExtrapStep.noise7_(4, 4));
        EXPECT_EQ(0, myExtrapStep.noise7_(4, 5));
        EXPECT_EQ(0, myExtrapStep.noise7_(4, 6));

        EXPECT_EQ(0, myExtrapStep.noise7_(5, 0));
        EXPECT_EQ(0, myExtrapStep.noise7_(5, 1));
        EXPECT_EQ(0, myExtrapStep.noise7_(5, 2));
        EXPECT_EQ(0, myExtrapStep.noise7_(5, 3));
        EXPECT_EQ(0, myExtrapStep.noise7_(5, 4));
        EXPECT_EQ(0, myExtrapStep.noise7_(5, 5));
        EXPECT_EQ(0, myExtrapStep.noise7_(5, 6));

        EXPECT_EQ(0, myExtrapStep.noise7_(6, 0));
        EXPECT_EQ(0, myExtrapStep.noise7_(6, 1));
        EXPECT_EQ(0, myExtrapStep.noise7_(6, 2));
        EXPECT_EQ(0, myExtrapStep.noise7_(6, 3));
        EXPECT_EQ(0, myExtrapStep.noise7_(6, 4));
        EXPECT_EQ(0, myExtrapStep.noise7_(6, 5));
        EXPECT_EQ(0, myExtrapStep.noise7_(6, 6));
    }

    /// Black-Box-Test
    TEST_F (RKTrackRepTests, RKPropagate01) {
        genfit::Vector7 myState7;
        myState7[0] = 0;
        myState7[1] = 0;
        myState7[2] = 0;
        myState7[3] = 0;
        myState7[4] = 0;
        myState7[5] = 1;
        myState7[6] = 1;
        genfit::Matrix7x7* myJacobian = nullptr;
        genfit::Vector3 mySA;
        double myS = 0.5;
        const bool varField = false;
        const bool calcOnlyLastRowOfJ = false;

        genfit::RKTrackRep myRKTrackRep;
        EXPECT_EQ(10, myRKTrackRep.RKPropagate(myState7, myJacobian, mySA, myS, varField, calcOnlyLastRowOfJ));
        EXPECT_EQ(0, myState7[0]);
        EXPECT_EQ(0, myState7[1]);
        EXPECT_EQ(0.5, myState7[2]);
        EXPECT_EQ(0, myState7[3]);
        EXPECT_EQ(0, myState7[4]);
        EXPECT_EQ(1, myState7[5]);
        EXPECT_EQ(1, myState7[6]);
        EXPECT_EQ(0, mySA[0]);
        EXPECT_EQ(0, mySA[1]);
        EXPECT_EQ(0, mySA[2]);
    }

    /// Black-Box-Test
    TEST_F (RKTrackRepTests, RKPropagate02) {
        genfit::Vector7 myState7;
        myState7[0] = 1;
        myState7[1] = 1;
        myState7[2] = 1;
        myState7[3] = 1;
        myState7[4] = 1;
        myState7[5] = 1;
        myState7[6] = 1;
        genfit::Matrix7x7* myJacobian = nullptr;
        genfit::Vector3 mySA;
        double myS = 0.1;
        const bool varField = false;
        const bool calcOnlyLastRowOfJ = false;

        genfit::RKTrackRep myRKTrackRep;
        EXPECT_FLOAT_EQ(10, myRKTrackRep.RKPropagate(myState7, myJacobian, mySA, myS, varField, calcOnlyLastRowOfJ));
        EXPECT_FLOAT_EQ(1.1000299732532006, myState7[0]);
        EXPECT_FLOAT_EQ(1.0999700147633968, myState7[1]);
        EXPECT_FLOAT_EQ(1.1, myState7[2]);
        EXPECT_FLOAT_EQ(0.5776963359022331, myState7[3]);
        EXPECT_FLOAT_EQ(0.5770039949184069, myState7[4]);
        EXPECT_FLOAT_EQ(0.5773502691896258, myState7[5]);
        EXPECT_FLOAT_EQ(1, myState7[6]);
        EXPECT_FLOAT_EQ(0.000599405129044106, mySA[0]);
        EXPECT_FLOAT_EQ(-0.0005997646311051152, mySA[1]);
        EXPECT_FLOAT_EQ(0., mySA[2]);
    }

    /// White-Box-Test
    TEST_F (RKTrackRepTests, getState7) {
        RKTrackRep myRKTrackRep;
        genfit::Vector7 myState7(genfit::Vector7::Zero());

        genfit::MeasurementOnPlane myMeasurementOnPlane;
        EXPECT_THROW(myState7 = myRKTrackRep.getState7(myMeasurementOnPlane), genfit::Exception);
        EXPECT_EQ(0, myState7[0]);
        EXPECT_EQ(0, myState7[1]);
        EXPECT_EQ(0, myState7[2]);
        EXPECT_EQ(0, myState7[3]);
        EXPECT_EQ(0, myState7[4]);
        EXPECT_EQ(0, myState7[5]);
        EXPECT_EQ(0, myState7[6]);

        TVectorD myState5(5);
        myState5[0] = -1;
        myState5[1] = 1;
        myState5[2] = 1;
        myState5[3] = 0.1;
        myState5[4] = 0.1;
        genfit::SharedPlanePtr mySharedPlanePtr(new genfit::DetPlane(TVector3(0, 0, 1), TVector3(0, 0, 1), nullptr));
        genfit::StateOnPlane myStateOnPlane(myState5, mySharedPlanePtr, &myRKTrackRep);
        EXPECT_NO_THROW(myState7 = myRKTrackRep.getState7(myStateOnPlane));
        EXPECT_FLOAT_EQ(-0.1, myState7[0]);
        EXPECT_FLOAT_EQ(-0.1, myState7[1]);
        EXPECT_FLOAT_EQ(1, myState7[2]);
        EXPECT_FLOAT_EQ(-0.57735, myState7[3]);
        EXPECT_FLOAT_EQ(-0.57735, myState7[4]);
        EXPECT_FLOAT_EQ(0.57735, myState7[5]);
        EXPECT_FLOAT_EQ(-1, myState7[6]);

    }

    /// White-Box-Test
    TEST_F (RKTrackRepTests, getState5) {
        RKTrackRep myRKTrackRep;
        genfit::Vector7 myState7;
        // state7 must already lie on plane of state
        // We take the values from the getState7 test, because we know them.
        myState7[0] = -0.1;
        myState7[1] = -0.1;
        myState7[2] = 1;
        myState7[3] = -0.57735;
        myState7[4] = -0.57735;
        myState7[5] = 0.57735;
        myState7[6] = -1;
        TVectorD myState5(5);
        genfit::SharedPlanePtr mySharedPlanePtr(new genfit::DetPlane(TVector3(0, 0, 1), TVector3(0, 0, 1), nullptr));
        genfit::StateOnPlane myStateOnPlane(myState5, mySharedPlanePtr, &myRKTrackRep);
        EXPECT_NO_THROW(myRKTrackRep.getState5(myStateOnPlane, myState7));
        EXPECT_FLOAT_EQ(-0.1, myState7[0]);
        EXPECT_FLOAT_EQ(-0.1, myState7[1]);
        EXPECT_FLOAT_EQ(1, myState7[2]);
        EXPECT_FLOAT_EQ(-0.57735, myState7[3]);
        EXPECT_FLOAT_EQ(-0.57735, myState7[4]);
        EXPECT_FLOAT_EQ(0.57735, myState7[5]);
        EXPECT_FLOAT_EQ(-1, myState7[6]);

        EXPECT_EQ(-1, myStateOnPlane.getState()[0]);
        EXPECT_EQ(1, myStateOnPlane.getState()[1]);
        EXPECT_EQ(1, myStateOnPlane.getState()[2]);
        EXPECT_EQ(0.1, myStateOnPlane.getState()[3]);
        EXPECT_EQ(0.1, myStateOnPlane.getState()[4]);
    }

    /// White-Box-Test
    TEST_F (RKTrackRepTests, calcJ_pM_5x7) {
        RKTrackRep myRKTrackRep;

        // Code snippet from RKTrackRep to initialize test properly
        DetPlane myStartPlane(TVector3(0, 0, 0), TVector3(1, 1, 0));
        M1x3 pTilde = {{0.9, 1.1, 0.1}};
        const TVector3& normal = myStartPlane.getNormal();
        double pTildeW = pTilde[0] * normal.X() + pTilde[1] * normal.Y() + pTilde[2] * normal.Z();
        double spu = pTildeW > 0 ? 1 : -1;
        for (unsigned int i=0; i<3; ++i) {
            pTilde[i] *= spu/pTildeW; // | pTilde * W | has to be 1 (definition of pTilde)
        }
        // Code snippet end.
        Vector7 myStartState;
        myStartState << 0, 0, 0, pTilde[0], pTilde[1], pTilde[2], 1;
        const auto J_pMe = myRKTrackRep.calcJ_pM_5x7(
                myStartState,
                myStartPlane
        );

        EXPECT_FLOAT_EQ(0, J_pMe(0, 0));
        EXPECT_FLOAT_EQ(0, J_pMe(0, 1));
        EXPECT_FLOAT_EQ(0, J_pMe(0, 2));
        EXPECT_FLOAT_EQ(0, J_pMe(0, 3));
        EXPECT_FLOAT_EQ(0, J_pMe(0, 4));
        EXPECT_FLOAT_EQ(0, J_pMe(0, 5));
        EXPECT_FLOAT_EQ(1, J_pMe(0, 6));

        EXPECT_FLOAT_EQ(0, J_pMe(1, 0));
        EXPECT_FLOAT_EQ(0, J_pMe(1, 1));
        EXPECT_FLOAT_EQ(0, J_pMe(1, 2));
        EXPECT_FLOAT_EQ(0.7640964, J_pMe(1, 3));
        EXPECT_FLOAT_EQ(-0.62579853, J_pMe(1, 4));
        EXPECT_FLOAT_EQ(0.0069149, J_pMe(1, 5));
        EXPECT_FLOAT_EQ(0, J_pMe(1, 6));

        EXPECT_FLOAT_EQ(0, J_pMe(2, 0));
        EXPECT_FLOAT_EQ(0, J_pMe(2, 1));
        EXPECT_FLOAT_EQ(0, J_pMe(2, 2));
        EXPECT_FLOAT_EQ(0.044006158, J_pMe(2, 3));
        EXPECT_FLOAT_EQ(0.0537853, J_pMe(2, 4));
        EXPECT_FLOAT_EQ(-0.987694, J_pMe(2, 5));
        EXPECT_FLOAT_EQ(0, J_pMe(2, 6));

        EXPECT_FLOAT_EQ(0.707107, J_pMe(3, 0));
        EXPECT_FLOAT_EQ(-0.707107, J_pMe(3, 1));
        EXPECT_FLOAT_EQ(0, J_pMe(3, 2));
        EXPECT_FLOAT_EQ(0, J_pMe(3, 3));
        EXPECT_FLOAT_EQ(0, J_pMe(3, 4));
        EXPECT_FLOAT_EQ(0, J_pMe(3, 5));
        EXPECT_FLOAT_EQ(0, J_pMe(3, 6));

        EXPECT_FLOAT_EQ(0, J_pMe(4, 0));
        EXPECT_FLOAT_EQ(0, J_pMe(4, 1));
        EXPECT_FLOAT_EQ(-1, J_pMe(4, 2));
        EXPECT_FLOAT_EQ(0, J_pMe(4, 3));
        EXPECT_FLOAT_EQ(0, J_pMe(4, 4));
        EXPECT_FLOAT_EQ(0, J_pMe(4, 5));
        EXPECT_FLOAT_EQ(0, J_pMe(4, 6));
    }

    /// White-Box-Test
    TEST_F (RKTrackRepTests, transformPM6) {
        // TODO: Implement
    }

    /// White-Box-Test
    TEST_F (RKTrackRepTests, calcJ_Mp_7x5) {
        RKTrackRep myRKTrackRep;

        // Code snippet from RKTrackRep to initialize test properly
        DetPlane myDestPlane(TVector3(0, 0, 0), TVector3(1, 1, 0));
        M1x3 pTilde = {{0.9, 1.1, 0.1}};
        const TVector3& normal = myDestPlane.getNormal();
        double pTildeW = pTilde[0] * normal.X() + pTilde[1] * normal.Y() + pTilde[2] * normal.Z();
        double spu = pTildeW > 0 ? 1 : -1;
        for (unsigned int i=0; i<3; ++i) {
            pTilde[i] *= spu/pTildeW; // | pTilde * W | has to be 1 (definition of pTilde)
        }
        // Code snippet end.
        Vector7 myDestState;
        myDestState << 0, 0, 0, pTilde[0], pTilde[1], pTilde[2], 1;
        const auto J_Mpe = myRKTrackRep.calcJ_Mp_7x5(
                myDestState, myDestPlane
        );

        EXPECT_FLOAT_EQ(0, J_Mpe(0, 0));
        EXPECT_FLOAT_EQ(0, J_Mpe(0, 1));
        EXPECT_FLOAT_EQ(0, J_Mpe(0, 2));
        EXPECT_FLOAT_EQ(0.707107, J_Mpe(0, 3));
        EXPECT_FLOAT_EQ(0, J_Mpe(0, 4));

        EXPECT_FLOAT_EQ(0, J_Mpe(1, 0));
        EXPECT_FLOAT_EQ(0, J_Mpe(1, 1));
        EXPECT_FLOAT_EQ(0, J_Mpe(1, 2));
        EXPECT_FLOAT_EQ(-0.707107, J_Mpe(1, 3));
        EXPECT_FLOAT_EQ(0, J_Mpe(1, 4));

        EXPECT_FLOAT_EQ(0, J_Mpe(2, 0));
        EXPECT_FLOAT_EQ(0, J_Mpe(2, 1));
        EXPECT_FLOAT_EQ(0, J_Mpe(2, 2));
        EXPECT_FLOAT_EQ(0, J_Mpe(2, 3));
        EXPECT_FLOAT_EQ(-1, J_Mpe(2, 4));

        EXPECT_FLOAT_EQ(0, J_Mpe(3, 0));
        EXPECT_FLOAT_EQ(0.77781749, J_Mpe(3, 1));
        EXPECT_FLOAT_EQ(0.05, J_Mpe(3, 2));
        EXPECT_FLOAT_EQ(0, J_Mpe(3, 3));
        EXPECT_FLOAT_EQ(0, J_Mpe(3, 4));

        EXPECT_FLOAT_EQ(0, J_Mpe(4, 0));
        EXPECT_FLOAT_EQ(-0.636396, J_Mpe(4, 1));
        EXPECT_FLOAT_EQ(0.05, J_Mpe(4, 2));
        EXPECT_FLOAT_EQ(0, J_Mpe(4, 3));
        EXPECT_FLOAT_EQ(0, J_Mpe(4, 4));

        EXPECT_FLOAT_EQ(0, J_Mpe(5, 0));
        EXPECT_FLOAT_EQ(0, J_Mpe(5, 1));
        EXPECT_FLOAT_EQ(-1, J_Mpe(5, 2));
        EXPECT_FLOAT_EQ(0, J_Mpe(5, 3));
        EXPECT_FLOAT_EQ(0, J_Mpe(5, 4));

        EXPECT_FLOAT_EQ(1, J_Mpe(6, 0));
        EXPECT_FLOAT_EQ(0, J_Mpe(6, 1));
        EXPECT_FLOAT_EQ(0, J_Mpe(6, 2));
        EXPECT_FLOAT_EQ(0, J_Mpe(6, 3));
        EXPECT_FLOAT_EQ(0, J_Mpe(6, 4));
    }

    /// White-Box-Test
    TEST_F (RKTrackRepTests, calcForwardJacobianAndNoise) {
        const TVector3 startPlaneO(0, 0, 1);
        const TVector3 startPlaneN(0, 0, 1);
        const TVector3 destPlaneO(0, 0, -1);
        const TVector3 destPlaneN(0, 0, 1);

        genfit::RKTrackRep myRKTrackRep;
        genfit::DetPlane myStartPlane(startPlaneO, startPlaneN);
        genfit::DetPlane myDestPlane(destPlaneO, destPlaneN);
        genfit::Vector7 myStartState;
        genfit::Vector7 myDestState;

        EXPECT_EQ(0, myRKTrackRep.ExtrapSteps_.size());
        EXPECT_THROW(myRKTrackRep.calcForwardJacobianAndNoise(myStartState, myStartPlane, myDestState, myDestPlane),
                     genfit::Exception);
    }

    /// White-Box-Test
    TEST_F (RKTrackRepTests, transformM6P) {
        // TODO: Implement
    }

    /// White-Box-Test
    TEST_F (RKTrackRepTests, RKutta) {
        // TODO: Implement
    }

    /// White-Box-Test
    TEST_F (RKTrackRepTests, estimateStep) {
        // TODO: Implement
    }

    /// White-Box-Test
    TEST_F (RKTrackRepTests, Extrap) {
        // TODO: Implement
    }

    /// White-Box-Test
    TEST_F (RKTrackRepTests, momMag) {
        genfit::RKTrackRep myRKTrackRep;
        genfit::M1x7 myState7 = {0, 0, 0, 0, 0, 0, 0};
        EXPECT_EQ(std::numeric_limits<double>::infinity(), myRKTrackRep.momMag(myState7));
        myState7 = {0, 0, 0, 0, 0, 0, 1};
        EXPECT_EQ(1.0, myRKTrackRep.momMag(myState7));
        myState7 = {0, 0, 0, 0, 0, 0, -1};
        EXPECT_EQ(1.0, myRKTrackRep.momMag(myState7));
    }

}
