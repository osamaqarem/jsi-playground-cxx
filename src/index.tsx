import { NativeModules } from 'react-native';

type ImageColorsType = {
  multiply(a: number, b: number): Promise<number>;
};

const { ImageColors } = NativeModules;

export default ImageColors as ImageColorsType;
