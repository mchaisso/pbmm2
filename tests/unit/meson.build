pbmm2_test_cpp_sources = files([
  'MM2Test.cpp'])

pbmm2_TestData_h_config = configuration_data()
pbmm2_TestData_h_config.set('PBMM2_TestsDir', meson.current_source_dir())
# pbmm2_TestData_h_config.set('CMAKE_BINARY_DIR', meson.current_build_dir())
pbmm2_TestData_h = configure_file(
  input : files('TestData.h.in'),
  output : 'TestData.h',
  configuration : pbmm2_TestData_h_config)
pbmm2_test_cpp_sources += pbmm2_TestData_h

# find GoogleTest and GoogleMock
pbmm2_gmock_main_dep = dependency('gmock_main', fallback : ['gtest', 'gmock_main_dep'])

pbmm2_test = executable(
  'pbmm2_test',
  pbmm2_test_cpp_sources,
  dependencies : [
    pbmm2_boost_dep,
    pbmm2_zlib_dep,
    pbmm2_pbbam_dep,
    pbmm2_pbcopper_dep,
    pbmm2_minimap2_dep,
    pbmm2_gmock_main_dep],
  include_directories : pbmm2_include_directories,
  link_with : pbmm2_lib,
  cpp_args : pbmm2_flags,
  install : false)

test(
  'pbmm2 gtest unittests',
  pbmm2_test,
  args : [
    '--gtest_output=xml:' + join_paths(meson.build_root(), 'unit.xml')],
  env : [
    'ARGS=-V',
    'VERBOSE=1'],
  timeout : 1800)
