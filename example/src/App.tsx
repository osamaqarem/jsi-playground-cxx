import * as React from 'react';
import { StyleSheet, View, Text } from 'react-native';

declare function multiply(x: number, y: number): number;

export default function App() {
  const [result, setResult] = React.useState<number | undefined>();

  React.useEffect(() => {
    const process = async () => {
      const res = multiply(Math.random() * 10 + 1, Math.random() * 10 + 1);
      setResult(res);
    };

    setInterval(() => {
      process();
    }, 1000);
  }, []);

  return (
    <View style={styles.container}>
      <Text>Result: {result}</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  box: {
    width: 60,
    height: 60,
    marginVertical: 20,
  },
});
