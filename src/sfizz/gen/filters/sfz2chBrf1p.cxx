/* ------------------------------------------------------------
author: "Jean Pierre Cimalando"
license: "BSD-2-Clause"
name: "sfz_filters"
Code generated with Faust 2.20.2 (https://faust.grame.fr)
Compilation options: -lang cpp -inpl -double -ftz 0
------------------------------------------------------------ */

#ifndef  __faust2chBrf1p_H__
#define  __faust2chBrf1p_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <algorithm>
#include <cmath>
#include <math.h>


#ifndef FAUSTCLASS
#define FAUSTCLASS faust2chBrf1p
#endif

#ifdef __APPLE__
#define exp10f __exp10f
#define exp10 __exp10
#endif

class faust2chBrf1p : public sfzFilterDsp {

 public:

	int fSampleRate;
	double fConst0;
	double fConst1;
	FAUSTFLOAT fCutoff;
	double fConst2;
	double fRec2[2];
	double fRec1[2];
	double fRec0[2];
	double fRec4[2];
	double fRec3[2];

 public:

	void metadata(Meta* m) {
	}

	virtual int getNumInputs() {
		return 2;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	virtual int getInputRate(int channel) {
		int rate;
		switch ((channel)) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	virtual int getOutputRate(int channel) {
		int rate;
		switch ((channel)) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}

	static void classInit(int sample_rate) {
	}

	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<double>(192000.0, std::max<double>(1.0, double(fSampleRate)));
		fConst1 = (6.2831853071795862 / fConst0);
		fConst2 = std::exp((0.0 - (1000.0 / fConst0)));
	}

	virtual void instanceResetUserInterface() {
		fCutoff = FAUSTFLOAT(440.0);
	}

	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec2[l0] = 0.0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec1[l1] = 0.0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec0[l2] = 0.0;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec4[l3] = 0.0;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec3[l4] = 0.0;
		}
	}

	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}

	virtual faust2chBrf1p* clone() {
		return new faust2chBrf1p();
	}

	virtual int getSampleRate() {
		return fSampleRate;
	}

	virtual void buildUserInterface(UI* ui_interface) {
	}

	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		double fSlow0 = (fSmoothEnable ? fConst2 : 0.0);
		double fSlow1 = (((fConst1 * double(fCutoff)) + -1.0) * (1.0 - fSlow0));
		for (int i = 0; (i < count); i = (i + 1)) {
			double fTemp0 = double(input0[i]);
			double fTemp1 = double(input1[i]);
			fRec2[0] = (fSlow1 + (fSlow0 * fRec2[1]));
			fRec1[0] = (fTemp0 - (fRec2[0] * fRec1[1]));
			fRec0[0] = (fRec1[1] + (fRec2[0] * (fRec1[0] - fRec0[1])));
			output0[i] = FAUSTFLOAT((fTemp0 + (fRec0[1] + (fRec2[0] * fRec0[0]))));
			fRec4[0] = (fTemp1 - (fRec2[0] * fRec4[1]));
			fRec3[0] = (fRec4[1] + (fRec2[0] * (fRec4[0] - fRec3[1])));
			output1[i] = FAUSTFLOAT((fTemp1 + (fRec3[1] + (fRec2[0] * fRec3[0]))));
			fRec2[1] = fRec2[0];
			fRec1[1] = fRec1[0];
			fRec0[1] = fRec0[0];
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
		}
	}

};

#endif
