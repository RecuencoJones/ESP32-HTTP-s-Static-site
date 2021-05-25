import { defineConfig } from 'vite';
import vue from '@vitejs/plugin-vue';

export default defineConfig({
    build: {
        assetsDir: 'a'
    },
    plugins: [vue()],
    resolve: {
        alias: {
            vue: 'https://cdn.jsdelivr.net/npm/vue@3.0.11/dist/vue.esm-browser.prod.js'
        }
    }
});