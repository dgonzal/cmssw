# how to test HadShower ~independent from CMSSW

## setup
```
cmsrel CMSSW_7_6_0_pre4
cd CMSSW_7_6_0_pre4/src
cmsenv
git cms-merge-topic lveldere:fastsim-hadshower
cd FastSimulation/HadShower/test
make program=test_start.C
make program=test_stepFactory.C
```

## run

```
./bin/test_start          # test the generation of the shower starting piont
./bin/test_stepFactory    # test the creation of shower steps
./bin/test_singleShapeParametersGenerator   # test the generation of shower shape parameters
./bin/test_showerShape    # comprehensive test of shower generation
```
