# Introduction

The package FastSimulation/HadShower contains a fast model for hadronic showers int the CMS calorimeter system.


# Installation

## collect the package

```
cmsrel CMSSW_A_B_C  # e.g. CMSSW_7_6_0_pre4
cd CMSSW_A_B_C/src
cmsenv
git cms-merge-topic lveldere:fastsim-hadshower
```

## compile outside CMSSW

```
# setup CMSSW in order to use correct compiler, root version, etc.
cd CMSSW_A_B_C/src
cmsenv
# then compile
cd FastSimulation/HadShower/test
make # use option -j 8 to gain speed
```

## run outside CMSSW

```
# setup CMSSW in order to use correct interpreter, root version, etc.
cd CMSSW_A_B_C/src
cmsenv
# and run
./bin/test_start                      # test the generation of the shower starting piont
./bin/test_stepFactory                # test the creation of shower steps
./bin/test_shapeParametersGenerator   # test the generation of shower shape parameters
./bin/test_shape                      # comprehensive test of shower generation
```

## compile inside CMSSW

under development

## run inside CMSSW

under development



# Package Description

## Units

Energy is expressed in GeV.

Distance is mostly expressed in the units of interaction length.
Alternative units are centimeter and radiation lenght.
Whenever one or another variable is expressed in these alternative units,
this is made clear in the code by letting the variable name end with InCm or InRadLen.

## Material

It is assumed that the trajectoy of any particle that hits the calorimeter first passes through ECAL, 
then a gap between ECAL and HCAL, and finally HCAL.
For any given particle the calorimeter is simply described by the distance the particle's trajectory 
travels through ECAL, the gap and HCAL.

## Shower start

The class hadshower::StartGenerator decides the distance the particle travels through the calorimeter material before it starts showering.
This distance is a random number drawn from a simple exponential.
Since the distance unit used is interaction length the mean of the exponential distribution is chosen to be 1.

See test/test_start.C for an example illustrating the usage of hadshower::StartGenerator.

## Shower shape parameters

Given the energy of the incident particle, the class hadshower::ShapeParametersGenerator calculates the mean shower shape parameters.
Then, the actually parameter values are drawn randomly around the mean values,
modeling fluctuations in the shower shape.

See test/test_shapeParametersGenerator.C for an example illustrating the usage of hadshower::ShapeParametersGenerator.

## Shower steps

Given the starting point of the shower (modeled in hadshower::StartGenerator),
the class hadshower::StepsFactory calculates the position and size of the steps (bins) in which the shower is modeled.

The first step starts at the starting point.

If the shower starts in ECAL, there is one step in ECAL.

If the shower starts in the gap or in ECAL, there is one step in the gap and one in ECAL.

Steps in HCAL have all the same size.
The number of HCAL steps is such that all steps fit inside the HCAL volume and is not more than a certain maximum.

See test/test_stepFactory.C for an example illustrating the usage of hadshower::ShapeParametersGenerator.

## Shower modeling

Given the starting point and the shape parameters,
the constructor of the class hadshower::Shape obtains the shower steps using the hadshower::StepsFactory.
Then it calculates and stores for each step how much of the shower's energy it contains, and the transverse size of the shower.
Shape::generateEnergySpot allows to draw positions in the transverse plain defined by a given step,
distributed according to the transverse energy profile at the center of the step.

See test/test_shape.C for an example illustrating the usage of hadshower::Shape.
