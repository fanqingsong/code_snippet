/** @type {import('next').NextConfig} */
const nextConfig = {
  assetPrefix: ".",
  images: {
    loader: 'akamai',
    path: '',
  },
}

module.exports = nextConfig
